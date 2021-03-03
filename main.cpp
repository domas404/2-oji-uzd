#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <random>
#include <chrono>
#include <fstream>
#include <time.h>
#include <algorithm>

using namespace std;

using hrClock = chrono::high_resolution_clock;
mt19937 mt(static_cast<long unsigned int>(hrClock::now().time_since_epoch().count()));
uniform_int_distribution<int> dist(1, 10);

const int nmax=10000000;    //maksimalus studentu skaicius

//Saugomi studento duomenys
struct Studentas {
    string vardas, pavarde; // vardas, pavarde
    vector<int> ND;         // namu darbu ivertinimai
    int egz;                // egzamino rezultatas
    string vm;              // ar galutinis pazymys generuojamas su vidurkiu ar mediana
    float final;            // galutinis pazymys
};
// funkcija, nuskaitanti studento varda ir pavarde
void Name(Studentas &S){
    cout << "Iveskite studento varda: ";
    getline(cin, S.vardas);
    cout << "Iveskite studento pavarde: ";
    getline(cin, S.pavarde);
}
// funkcija, generuojanti atsitiktinius namu darbu ivertinimus
void Generavimas(int n, vector<int> &ND){
    for (int i=0; i<n; i++){
        ND.push_back(dist(mt));
    }
}
// funkcija, skaiciuojanti ivertinimu mediana
float Mediana(int nd, vector<int> ND){
    int a, b;
    float vid;
    if (nd%2==1){
        a = nd/2;
        vid = ND[a];
    }
    else {
        a = nd/2-1;
        b = nd/2;
        vid = (float)(ND[a] + ND[b])/2;
    }
    return vid;
}
// funkcija, skaiciuojanti ivertinimu vidurki
float Vidurkis(int nd, vector<int> ND){
    int suma=0;
    for (int i=0; i<nd; i++){
        suma += ND[i];
    }
    return (float)suma/nd;
}
// funkcija, apdorojanti visus duomenis susijusius su namu darbais
void Namu_darbai(Studentas M, float &vid){
    int nd=0;       // atliktu namu darbu kiekis
    int paz;        // pazymiai (suvedinejimui)
    string a, b;    // tarpiniai kintamieji, igyjantys viena is dvieju reiksmiu pvz. (y/n)
    do {
        cout << "Ar zinote kiek namu darbu atliko studentas? (y/n) ";
        cin >> a;
    } while(a != "y" && a != "n");

        if (a == "y"){
            do {
                cout << "Iveskite atliktu namu darbu kieki: ";
                cin >> nd;
            } while(nd < 0 || nd > 1000);
            if (nd > 0){
                do {
                    cout << "Ivertinimus norite suvesti [r]ankiniu budu ar [s]ugeneruoti atsitiktinius? ";
                    cin >> b;
                } while (b == "r" && b == "s");

                if (b == "s") {
                    cout << "Sugeneruoti namu darbu ivertinimai: ";
                    Generavimas(nd, M.ND);
                    for (int i=0; i<nd; i++)
                        cout << M.ND[i] << " ";
                    cout << endl;
                }
                else if (b == "r") {
                    cout << "Iveskite namu darbu ivertinimus: ";
                    for (int k=0; k<nd; k++){
                        cin >> paz;
                        M.ND.push_back(paz);
                    }
                }
            }
        }
        else {
            cout << "Iveskite namu darbu ivertinimus intervale [1;10]. Kai baigsite suvedineti duomenis, iveskite [0] ir spustelekite 'enter': " << endl;
            while (true){
                cin >> paz;
                if (paz == 0) break;
                M.ND.push_back(paz);
                nd++;
            }
        }
        if (nd != 0){
            cout << "Ivertinimui naudoti [v]idurki ar [m]ediana? ";
            cin >> M.vm;
            if (M.vm == "m"){
                sort(M.ND.begin(), M.ND.end());
                vid = Mediana(nd, M.ND);
            }
            else if (M.vm == "v") vid = Vidurkis(nd, M.ND);
        }
}
//funkcija, apdorojanti duomenis, susijusius su egzaminu
void Egzaminas(Studentas &M) {
    string a;
    cout << "Ar studentas laike egzamina? (y/n) ";
    cin >> a;
    if (a == "y"){
        cout << "Ar zinote egzamino rezultata? (y/n) ";
        cin >> a;
        if (a == "n"){
            M.egz = dist(mt);
            cout << "Sugeneruotas egzamino rezultatas: " << M.egz << endl;
        }
        else {
            cout << "Iveskite egzamino ivertinima: ";
            cin >> M.egz;
        }
    }
    else M.egz = 0;
}
// funkcija, isvedanti rezultatus i konsole
void outputConsole (Studentas M[], int n){
    int k=76;
    int p=18;
    for (int i=0; i<k; i++)
        cout << "-";
    cout << endl;
    cout << setw(p) << left << "| Vardas" << setw(p) << left << "| Pavarde"
    << setw(39) << left << "| Galutinis (Vid.) / Galutinis (Med.)" << "|" << endl;
    for (int i=0; i<k; i++)
        cout << "=";
    cout << endl;
    for (int i=0; i<n; i++){
        cout << "| " << setw(p-2) << left << M[i].vardas << "| " << setw(p-2) << left << M[i].pavarde << "| ";
        if (M[i].vm == "v") cout << setw(37) << left << fixed << setprecision(2) << M[i].final << "|" << endl;
        else cout << setw(19) << left << " " << setw(18) << left << fixed << setprecision(2) << M[i].final << "|" << endl;
    }
    for (int i=0; i<k; i++)
        cout << "-";
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
// funkcija  sugeneruojanti ir irasanti studentu duomenis i tekstini faila
void Write_txt (int n, int nd){
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
        Generavimas(nd, ND);
        for (int j=0; j<nd; j++){
            k << setw(5) << ND[j] << " ";
        }
        egz=dist(mt);
        k << egz << endl;
        vardas = "Vardas";
        pavarde = "Pavarde";
        ND.clear();
    }
    k.close();
}
// funkcija, kuri nurodo, kiek laiko buvo generuojamas studentu sarasas
void Case(int a, int nd){
    clock_t pradzia, pabaiga;
    pradzia = clock();
    Write_txt(a, nd);
    pabaiga = clock();
    cout << setw(45) << left << "Studentu saraso generavimas uztruko: ";
    cout << 1.0 * (pabaiga - pradzia) / CLOCKS_PER_SEC << " s" << endl;
}
// funkcija nuskaitanti duomenis is tektinio failo
void Read(Studentas M[], int nd, int ap){
    ifstream k ("kursiokai.txt");
    int egz, p;
    float vid=0;
    vector<int> ND;
    if (k.is_open()){
        for (int j=0; j<ap; j++){
            k >> M[j].vardas >> M[j].pavarde;
            for (int i=0; i<nd; ++i){
                k >> p;
                M[j].ND.push_back(p);
            }
            k >> M[j].egz;
        }
    }
    else cout << "Neimanoma atidaryti failo" << endl;
    k.close();
}
// funkcija, apskaiciuojanti galutinius studentu rezultatus
void Calculate(Studentas M[], int ap, int nd){
    float vid=0;
    string vm;
    cout << "Ivertinimams naudoti [v]idurki ar [m]ediana? ";
    cin >> vm;
    clock_t pradzia, pabaiga;
    pradzia = clock();
    M[0].vm = vm;
    if (vm == "v"){
        for (int i=0; i<ap; i++){
            vid = Vidurkis(nd, M[i].ND);
            M[i].final = ((vid)*0.4) + (M[i].egz*0.6);
            vid=0;
        }
    }
    else if (vm == "m"){
        for (int i=0; i<ap; i++){
            sort(M[i].ND.begin(), M[i].ND.end());
            vid = Mediana(nd, M[i].ND);
            M[i].final = ((vid)*0.4) + (M[i].egz*0.6);
            vid=0;
        }
    }
    pabaiga = clock();
    cout << setw(45) << left << "Galutiniu ivertinimu skaiciavimai uztruko: ";
    cout << 1.0 * (pabaiga - pradzia) / CLOCKS_PER_SEC << " s" << endl;
}
int main(){
    Studentas *M = new Studentas[nmax];
    bool repeat = true; // ciklas kartojamas, kol igis reiksme false
    int j=0;            // studento indeksas
    float vid=0;        // namu darbu vidurkis
    string a, b;        // tarpiniai kintamieji, igyjantys viena is dvieju reiksmiu, pateiktu naudotojui pvz. (y/n)
    cout << "Norite duomenis nuskaityti is tekstinio [f]ailo ar [k]onsoles: ";
    cin >> b;
    cin.ignore();
    int sk, nd;        // sk - apimties pasirinkimas, nd - namu darbu ivertinimu kiekis
    int ap;            // studentu skaicius
    if (b == "f"){
        cout << "Pasirinkite norimu sugeneruoti studentu skaiciu: " << endl;
        cout << "[1] 10'000   [2] 100'000   [3] 1'000'000   [4] 10'000'000" << endl;
        cin >> sk;
        cout << "Kiek namu darbu pazymiu turi kiekvienas studentas? ";
        cin >> nd;
        switch(sk){
            case 1:
                ap = 10000;
                Case(ap, nd);
                break;
            case 2:
                ap = 100000;
                Case(ap, nd);
                break;
            case 3:
                ap = 1000000;
                Case(ap, nd);
                break;
            case 4:
                ap = 10000000;
                Case(ap, nd);
                break;
        }
        clock_t pradzia, pabaiga;
        pradzia = clock();
        Read(M, nd, ap);
        pabaiga = clock();
        cout << setw(45) << left << "Duomenu nuskaitymas uztruko: ";
        cout << 1.0 * (pabaiga - pradzia) / CLOCKS_PER_SEC << " s" << endl;

        Calculate(M, ap, nd);

        clock_t pradzia1, pabaiga1;
        pradzia1 = clock();
        outputFile(M, ap);
        pabaiga1 = clock();
        cout << setw(45) << left << "Duomenu irasymas i tekstini faila uztruko: ";
        cout << 1.0 * (pabaiga1 - pradzia1) / CLOCKS_PER_SEC << " s" << endl;
    }
    else if (b == "k") {
        do {
            Name(M[j]);
            Namu_darbai(M[j], vid);
            Egzaminas(M[j]);
            M[j].final = ((vid)*0.4) + (M[j].egz*0.6);
            j++;
            cout << "Ar norite ivesti kito studento duomenis? (y/n) ";
            cin >> a;
            if (a == "n")
                repeat=false;
            vid=0;
            cin.ignore();
        } while (repeat);
        outputConsole(M, j);
    }
    delete[] M;
    return 0;
}
