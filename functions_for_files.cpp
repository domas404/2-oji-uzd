#include "header.h"
#include "header_for_files.h"

// funkcija naudojama jei failas jau sukurtas
void openFile(int &nd, int &ap, Studentas M[]){
    string t;  // rankiniu budu ivestas tekstinio failo pavadinimas
    cout << "Iveskite failo pavadinima: ";
    cin >> t;
    cout << "Kiek namu darbu pazymiu turi kiekvienas studentas? ";
    cin >> nd;
    readFile(M, nd, ap, t+".txt");
}
// funkcija nuskaitanti duomenis is tekstinio failo
void readFile(Studentas M[], int nd, int &ap, string t){
    clock_t pr, pab;
    pr = clock();
    ifstream k(t);
    int egz, p;
    float vid=0;
    string line;
    int i=0;
    try{
        if (k.is_open()){
            while(!k.eof()){
                getline(k, line);
                istringstream iss(line);
                iss >> M[i].vardas >> M[i].pavarde;
                for (int j=0; j<nd; j++){
                    iss >> p;
                    M[i].ND.push_back(p);
                }
                iss >> M[i].egz;
                i++;
                ap++;
            }
            pab = clock();
            cout << setw(45) << left << "Duomenu nuskaitymas uztruko: ";
            cout << 1.0 * (pab - pr) / CLOCKS_PER_SEC << " s" << endl;
        }
        else throw(t);
    }
    catch(string t){
        cout << "Neimanoma atidaryti failo pavadinimu \"" << t << "\"" << endl;
        openFile(nd, ap, M);
    }
    k.close();
}
//funkcija, kurioje nurodomi norimo sugeneruoti studentu saraso parametrai
void createFile(int &nd, int &ap, Studentas M[]){
    int sk;
    cout << "Pasirinkite norimu sugeneruoti studentu skaiciu: " << endl;
    cout << "[1] 10'000   [2] 100'000   [3] 1'000'000   [4] 10'000'000" << endl;
    cin >> sk;
    cout << "Kiek namu darbu pazymiu turi kiekvienas studentas? ";
    cin >> nd;
    switch(sk){
        case 1:
            ap = 10000;
            Generate_txt(ap, nd);
            break;
        case 2:
            ap = 100000;
            Generate_txt(ap, nd);
            break;
        case 3:
            ap = 1000000;
            Generate_txt(ap, nd);
            break;
        case 4:
            ap = 10000000;
            Generate_txt(ap, nd);
            break;
    }
    ap=0;
    clock_t pradzia, pabaiga;
    pradzia = clock();
    readFile(M, nd, ap, "kursiokai.txt");
    pabaiga = clock();
    cout << setw(45) << left << "Duomenu nuskaitymas uztruko: ";
    cout << 1.0 * (pabaiga - pradzia) / CLOCKS_PER_SEC << " s" << endl;
}
// funkcija  sugeneruojanti ir irasanti studentu duomenis i tekstini faila
void Generate_txt (int n, int nd){
    clock_t pradzia, pabaiga;
    pradzia = clock();
    ofstream k("kursiokai.txt");
    string vardas = "Vardas", pavarde = "Pavarde";
    string a;
    vector<int> ND;
    int egz;
    for (int i=0; i<n; i++){
        a = to_string(i+1);
        vardas+=a;
        pavarde+=a;
        k << setw(16) << left << vardas << setw(16) << left << pavarde;
        for (int j=0; j<nd; j++){
            ND.push_back(myRandom());
            k << setw(5) << ND[j] << " ";
        }
        egz=myRandom();
        k << egz;
        if (i != n-1) k << endl;
        vardas = "Vardas";
        pavarde = "Pavarde";
        ND.clear();
    }
    k.close();
    pabaiga = clock();
    cout << setw(45) << left << "Studentu saraso generavimas uztruko: ";
    cout << 1.0 * (pabaiga - pradzia) / CLOCKS_PER_SEC << " s" << endl;
}
// funkcija, apskaiciuojanti galutinius studentu rezultatus
void Calculate(Studentas M[], int ap, int nd){
    float vid=0;
    string vm;
    cout << "Ivertinimams naudoti [v]idurki ar [m]ediana? ";
    cin >> vm;
    clock_t pradzia, pabaiga;
    pradzia = clock();
    for (int i=0; i<ap; i++)
        M[i].vm = vm;
    if (vm == "v"){
        for (int i=0; i<ap; i++){
            vid = Vidurkis(nd, M[i].ND);
            M[i].final = Final(vid, M[i].egz);
            vid=0;
        }
    }
    else if (vm == "m"){
        for (int i=0; i<ap; i++){
            sort(M[i].ND.begin(), M[i].ND.end());
            vid = Mediana(nd, M[i].ND);
            M[i].final = Final(vid, M[i].egz);
            vid=0;
        }
    }

    sort(M, M + ap, wayToSort);   // surikiuoja studentus pagal varda

    pabaiga = clock();
    cout << setw(45) << left << "Galutiniu ivertinimu skaiciavimai uztruko: ";
    cout << 1.0 * (pabaiga - pradzia) / CLOCKS_PER_SEC << " s" << endl;
}
//funkcija isvedanti rezultatus i tekstini faila
void outputFile (Studentas M[], int n){
    ofstream r("rezultatai.txt");
    int k=57;
    int p=18;
    for (int i=0; i<k; i++)
        r << "-";
    r << endl;
    r << setw(p) << left << "| Vardas" << setw(p) << left << "| Pavarde";
    if (M[0].vm == "v")
        r << setw(20) << left << "| Galutinis (Vid.)" << "|" << endl;
    else if (M[0].vm == "m")
        r << setw(20) << left << "| Galutinis (Med.)" << "|" << endl;
    for (int i=0; i<k; i++)
        r << "=";
    r << endl;
    for (int i=0; i<n; i++){
        r << "| " << setw(p-2) << left << M[i].vardas << "| " << setw(p-2) << left << M[i].pavarde << "| ";
        r << setw(p) << left << fixed << setprecision(2) << M[i].final << "|" << endl;
    }
    for (int i=0; i<k; i++)
        r << "-";
    r.close();
}