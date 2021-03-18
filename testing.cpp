#include "header.h"
#include "header_for_files.h"

// funkcija  sugeneruojanti ir irasanti studentu duomenis i tekstini faila
void generateFile(int n, int nd, string name){
    clock_t pradzia, pabaiga;
    pradzia = clock();
    ofstream k(name);
    string vardas = "Vardas", pavarde = "Pavarde";
    string a;
    vector<int> ND;
    int egz;
    string H="ND"; 

    k << setw(16) << left << "Vardas" << setw(16) << left << "Pavarde";
    for (int i=0; i<nd; i++){
        H += to_string(i+1);
        k << setw(5) << H << " ";
        H="ND";
    }
    k << "Egzaminas" << endl;

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
    cout << setw(8) << right << n << setw(50) << left << " studentu saraso generavimas uztruko: ";
    cout << 1.0 * (pabaiga - pradzia) / CLOCKS_PER_SEC << " s" << endl;
}
// isvalomi tarpinio strukturos kintamojo duomenys
void Clean(Studentas &A){
    A.vardas="";
    A.pavarde="";
    A.ND.clear();
    A.egz=0;
}
// nuskaitomi duomenys is tekstinio failo
void readFile(vector<Studentas> &M, int nd, string t, string vm){
    clock_t pradzia, pabaiga;
    int ap=0;
    pradzia = clock();
    ifstream input(t);
    int p;
    string line;
    int i=0;
    Studentas A;
    try{
        if (input.is_open()){
            getline(input, line);
            while(!input.eof()){
                getline(input, line);
                istringstream iss(line);
                iss >> A.vardas >> A.pavarde;
                for (int j=0; j<nd; j++){
                    iss >> p;
                    A.ND.push_back(p);
                }
                iss >> A.egz;
                if (vm == "v")
                    AssignVid(A, nd);
                else if (vm == "m")
                    AssignMed(A, nd);
                M.push_back(A);
                i++;
                ap++;
                Clean(A);
            }
        }
        else throw(t);
    }
    catch(string t){
        cout << "Neimanoma atidaryti failo pavadinimu \"" << t << "\"" << endl;
    }
    input.close();
    pabaiga = clock();
    cout << setw(8) << right << ap << setw(50) << left << " studentu nuskaitymas ir skaiciavimai uztruko: ";
    cout << 1.0 * (pabaiga - pradzia) / CLOCKS_PER_SEC << " s" << endl;
}
// skaiciuojamas protingu ir nelabai studentu isvedimo laikas
void outputTime(int ap, vector<Studentas> &G, int size, string title, string league, string vm){
    league += " rasymas i tekstini faila uztruko: ";
    clock_t pr, pab;
    pr = clock();
    outputFile(G, size, title, vm);
    pab = clock();
    cout << setw(8) << right << ap << setw(50) << left << league;
    cout << 1.0 * (pab - pr) / CLOCKS_PER_SEC << " s" << endl;
}
// studentu skirstymas i protingus ir ne
void distinctStudents(vector<Studentas> &M, int ap, string vm){
    clock_t pr, pab;
    pr = clock();
    vector<Studentas> Kietiakai;
    vector<Studentas> Varguoliai;
    Kietiakai.reserve(ap*0.6);
    int size_1=0, size_2=0;
    string p="kietiakai";
    string t="varguoliai";
    p += to_string(ap);
    t += to_string(ap);
    int j=ap-1;

    while (M[j].final >= 5){
        Kietiakai.push_back(M[j]);
        ++size_1;
        M.pop_back();
        --j;
    }
    Varguoliai.swap(M);
    size_2 = Varguoliai.size();
    pab = clock();
    cout << setw(8) << right << ap << setw(50) << left << " studentu skirstymas i dvi grupes uztruko: ";
    cout << 1.0 * (pab - pr) / CLOCKS_PER_SEC << " s" << endl;

    outputTime(ap, Kietiakai, size_1, p+".txt", " kietiaku", vm);
    Kietiakai.clear();
    outputTime(ap, Varguoliai, size_2, t+".txt", " varguoliu", vm);
    Varguoliai.clear();
}
// testuojami veiksmai su tam tikro dydzio studentu sarasu
void execusionTest(int ap, string title, string result, int nd, string vm){
    clock_t pr, pab;
    pr = clock();
    vector<Studentas> M;
    M.reserve(ap);
    generateFile(ap, nd, title);
    readFile(M, nd, title, vm);
    sortStudents(M, ap);
    distinctStudents(M, ap, vm);
    M.clear();
    pab = clock();
    cout << endl;
    cout << setw(8) << right << ap << setw(50) << left << " irasu testo laikas: ";
    cout << 1.0 * (pab - pr) / CLOCKS_PER_SEC << " s" << endl;
    cout << endl;
}
// i tekstini faila isvedami rezultatai
void outputFile(vector<Studentas> &M, int n, string t, string vm){
    ofstream r(t);
    int k=57, p=18;
    r  << setw(p) << left << "Vardas" << setw(p) << left << "Pavarde";
    if (vm == "v")
        r << setw(20) << left << "Galutinis (Vid.)" << endl;
    else if (vm == "m")
        r << setw(20) << left << "Galutinis (Med.)" << endl;
    for (int i=0; i<k; i++)
        r << "-";
    r << endl;
    for (int i=0; i<n; i++){
        r << setw(p) << left << M[i].vardas << setw(p) << left << M[i].pavarde;
        r << fixed << setprecision(2) << M[i].final << endl;
    }
    r.close();
}
