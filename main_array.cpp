#include <iostream>
#include <string>
#include <iomanip>
#include <time.h>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::setw;
using std::left;
using std::fixed;
using std::setprecision;
using std::swap;

const int nmax=50;

struct Studentas {
    string vardas, pavarde; //vardas, pavarde
    float final; //galutinis pazymys
    string vm; //ar galutinis generuojamas su vidurkiu ar mediana
};

void Generavimas(int n, int ND[]){
    srand(time(NULL));
    for (int i=0; i<n; i++){
        ND[i]=rand()%10+1;
        cout << ND[i] << " ";
    }
}

void Rikiavimas(int nd, int ND[]){
    for (int i=0; i<nd-1; i++){
        for (int j=i; j<nd; j++){
            if (ND[i] > ND[j])
                swap(ND[i], ND[j]);
        }
    }
}

float Mediana(int nd, int ND[]){
    
    int a, b;
    float vid;
    if (nd%2==1){
        a = (float)ceil(nd/2);
        vid = ND[a];
    }
    else {
        a = nd/2-1;
        b = nd/2;
        vid = (float)(ND[a] + ND[b])/2;
    }
    return vid;
}

float Vidurkis(int nd, int ND[]){
    int suma=0;
    for (int i=0; i<nd; i++){
        suma += ND[i];
    }
    return (suma/nd);
}

void Egzaminas(string a, int &egz) {
    srand(time(NULL));
    cout << "Ar studentas laike egzamina? (y/n) ";
    cin >> a;
    if (a == "y"){
        cout << "Ar zinote egzamino rezultata? (y/n) ";
        cin >> a;
        if (a == "n"){
            egz = rand()%10+1;
            cout << "Sugeneruotas egzamino rezultatas: " << egz << endl;
        }
        else if (a == "y"){
            cout << "Iveskite egzamino ivertinima: ";
            cin >> egz;
        }
    }
}

void Output (Studentas M[], int n){
    cout << "--------------------------------------------------------------------" << endl;
    cout << setw(14) << left << "| Vardas" << setw(14) << left << "| Pavarde"
    << setw(39) << left << "| Galutinis (Vid.) / Galutinis (Med.)" << "|" << endl;
    cout << "====================================================================" << endl;
    for (int i=0; i<n; i++){
        cout << "| " << setw(12) << left << M[i].vardas << "| " << setw(12) << left << M[i].pavarde
        << "| ";
        if (M[i].vm == "v") cout << setw(37) << left << fixed << setprecision(2) << M[i].final << "|" << endl;
        else cout << setw(19) << left << " " << setw(18) << left << fixed << setprecision(2) << M[i].final << "|" << endl;
    }
    cout << "--------------------------------------------------------------------" << endl;
}

int main(){
    Studentas *M = new Studentas[nmax]; //masyvus i sujungta sarasa
    bool repeat = true;
    int j=0, nd=0, egz=0, paz;
    int *ND = new int[nmax];
    float vid=0;
    string a, b;
    do {
        cout << "Iveskite studento varda ir pavarde: ";
        cin >> M[j].vardas >> M[j].pavarde;

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
                Rikiavimas (nd, ND);;
                vid = Mediana(nd, ND);
            }
            else if (M[j].vm == "v") vid = Vidurkis(nd, ND);
        }
        Egzaminas (a, egz);

        M[j].final = ((vid)*0.4) + (egz*0.6);
        j++;
        vid = 0;
        cout << "Ar norite ivesti kito studento duomenis? (y/n) ";
        cin >> a;
        if (a == "n") repeat=false;
        nd=0;
        egz=0;

    } while (repeat);

    Output(M, j);

    return 0;
}
