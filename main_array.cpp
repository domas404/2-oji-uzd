#include <iostream>
#include <string>
#include <iomanip>
#include <random>
#include <chrono>
#include <algorithm>

using namespace std;

using hrClock = chrono::high_resolution_clock;
mt19937 mt(static_cast<long unsigned int>(hrClock::now().time_since_epoch().count()));
uniform_int_distribution<int> dist(1, 10);

const int nmax=50;

//Saugomi studento duomenys
struct Studentas {
    string vardas, pavarde; //vardas, pavarde
    float final; //galutinis pazymys
    string vm; //ar galutinis generuojamas su vidurkiu ar mediana
};
// funkcija, nuskaitanti studento varda ir pavarde
void Name(Studentas &S){
    cout << "Iveskite studento varda: ";
    getline(cin, S.vardas);
    cout << "Iveskite studento pavarde: ";
    getline(cin, S.pavarde);
}
// funkcija, generuojanti atsitiktinius namu darbu ivertinimus
void Generavimas(int n, int ND[]){
    for (int i=0; i<n; i++){
        ND[i]=dist(mt);
        cout << ND[i] << " ";
    }
}
// funkcija, skaiciuojanti ivertinimu mediana
float Mediana(int nd, int ND[]){
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
float Vidurkis(int nd, int ND[]){
    int suma=0;
    for (int i=0; i<nd; i++){
        suma += ND[i];
    }
    return (float)suma/nd;
}
// funkcija, apdorojanti visus duomenis susijusius su namu darbais
void Namu_darbai(Studentas M[], float &vid, int j){
    int nd=0;                // atliktu namu darbu kiekis
    int paz;                 // pazymiai (suvedinejimui)
    int *ND = new int[nmax]; // namu darbu pazymiai
    string a, b;             // tarpiniai kintamieji, igyjantys viena is dvieju reiksmiu pvz. (y/n)
    cout << "Ar zinote kiek namu darbu atliko studentas? (y/n) ";
        cin >> a;
        if (a == "y"){
            cout << "Iveskite atliktu namu darbu kieki: ";
            cin >> nd;
            while (nd < 0 || nd > 50) {
                cout << "Iveskite atliktu namu darbu kieki intervale [0;50]: ";
                cin >> nd;
            }
            if (nd > 0){
                do {
                    cout << "Ivertinimus norite suvesti [r]ankiniu budu ar [s]ugeneruoti atsitiktinius? ";
                    cin >> b;
                    if (b == "r" || b == "s") break;
                } while (true);

                if (b == "s") {
                    cout << "Sugeneruoti namu darbu ivertinimai: ";
                    Generavimas(nd, ND);
                    cout << endl;
                }
                else if (b == "r") {
                    cout << "Iveskite namu darbu ivertinimus: ";
                    for (int k=0; k<nd; k++){
                        cin >> ND[k];
                    }
                }
            }
        }
        else {
            cout << "Iveskite namu darbu ivertinimus intervale [1;10]. Kai baigsite suvedineti duomenis, iveskite [0] ir spustelekite 'enter': ";
            while (true){
                cin >> paz;
                if (paz == 0) break;
                ND[nd] = paz;
                nd++;
            }
        }
        if (nd != 0){
            cout << "Ivertinimui naudoti [v]idurki ar [m]ediana? ";
            cin >> M[j].vm;
            if (M[j].vm == "m"){
                sort(ND, ND + nd);
                vid = Mediana(nd, ND);
            }
            else if (M[j].vm == "v") vid = Vidurkis(nd, ND);
        }
    delete[] ND;
}
//funkcija, apdorojanti duomenis, susijusius su egzaminu
int Egzaminas() {
    int egz=0;
    string a;
    cout << "Ar studentas laike egzamina? (y/n) ";
    cin >> a;
    if (a == "y"){
        cout << "Ar zinote egzamino rezultata? (y/n) ";
        cin >> a;
        if (a == "n"){
            egz = dist(mt);
            cout << "Sugeneruotas egzamino rezultatas: " << egz << endl;
        }
        else if (a == "y"){
            cout << "Iveskite egzamino ivertinima: ";
            cin >> egz;
        }
    }
    return egz;
}
// funkcija, isvedanti rezultatus i konsole, lenteles pavidalu
void Output (Studentas M[], int n){
    int ilg=M[0].vardas.length();
    for (int i=1; i<n; i++){
        if (M[i].vardas.length() > ilg)
            ilg = M[i].vardas.length();
    }
    int k=68;
    int p=14;
    if (ilg > 11){
        p = ilg+3;
        k = k-28+(2*p);
    }
    for (int i=0; i<k; i++)
        cout << "-";
    cout << endl;
    cout << setw(p) << left << "| Vardas" << setw(p) << left << "| Pavarde"
    << setw(39) << left << "| Galutinis (Vid.) / Galutinis (Med.)" << "|" << endl;
    for (int i=0; i<k; i++)
        cout << "=";
    cout << endl;
    for (int i=0; i<n; i++){
        cout << "| " << setw(p-2) << left << M[i].vardas << "| " << setw(p-2) << left << M[i].pavarde
        << "| ";
        if (M[i].vm == "v") cout << setw(37) << left << fixed << setprecision(2) << M[i].final << "|" << endl;
        else cout << setw(19) << left << " " << setw(18) << left << fixed << setprecision(2) << M[i].final << "|" << endl;
    }
    for (int i=0; i<k; i++)
        cout << "-";
    cout << endl;
}

int main(){
    Studentas *M = new Studentas[nmax];
    bool repeat = true; // ciklas kartojamas, kol igis reiksme false
    int j=0, egz;       // j - studento indeksas, egz - egzamino pazymys
    float vid=0;        // namu darbu vidurkis
    string a;           // tarpiniai kintamieji, igyjantys viena is dvieju reiksmiu, pateiktu naudotojui pvz. (y/n)
    do {
        Name(M[j]);
        Namu_darbai(M, vid, j);
        egz = Egzaminas();
        M[j].final = ((vid)*0.4) + (egz*0.6);
        j++;
        vid = 0;
        cout << "Ar norite ivesti kito studento duomenis? (y/n) ";
        cin >> a;
        if (a == "n")
            repeat=false;
        vid=0;
        egz=0;
        cin.ignore();
    } while (repeat);
    Output(M, j);
    delete[] M;
    return 0;
}
