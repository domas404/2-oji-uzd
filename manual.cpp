#include "header.h"

// duomenu ivedimui naudojama konsole
void usingConsole(vector<Studentas> M, Studentas A){
    float vid=0;
    int j=0; // studento indeksas
    bool repeat;
    string a;
    do {
        A = Namu_darbai(vid);
        Egzaminas(A);
        A.final = Final(vid, A.egz);
        M.push_back(A);
        sort (M.begin(), M.end(), wayToSort);
        cout << "Ar norite ivesti kito studento duomenis? (y/n) ";
        cin >> a;
        if (a == "n")
            repeat=false;
        else j++;
        vid=0;
        cin.ignore();
    } while (repeat);
    outputConsole(M, j+1);
}
// nuskaitomi studento vardas ir pavarde
void readName(Studentas &S){
    cout << "Iveskite studento varda: ";
    getline(cin, S.vardas);
    cout << "Iveskite studento pavarde: ";
    getline(cin, S.pavarde);
}
// apdorojami visi duomenys susije su namu darbais
Studentas Namu_darbai(float vid){
    Studentas A;
    int nd=0, ndc;  // nd - atliktu namu darbu kiekis, ndc - nd kopija
    int paz;        // pazymiai (suvedinejimui)
    string a, b;    // tarpiniai kintamieji, igyjantys viena is dvieju reiksmiu pvz. (y/n)
    readName(A);
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
                    for (int i=0; i<nd; i++){
                        A.ND.push_back(myRandom());
                        cout << A.ND[i] << " ";
                    }
                    cout << endl;
                }
                else if (b == "r") {
                    ndc=nd;
                    cout << "Iveskite namu darbu ivertinimus: ";
                    for (int k=0; k<ndc; k++){
                        try {
                            cin >> paz;
                            if (paz<=10 && paz>0)
                                A.ND.push_back(paz);
                            else throw(paz);
                        }
                        catch(int paz){
                            cout << "Ivertinimas \"" << paz << "\" netinkamas. Iveskite skaiciu intervale [1;10]" << endl;
                            ndc++;
                        }
                    }
                }
            }
        }
        else {
            cout << "Iveskite namu darbu ivertinimus intervale [1;10]. Kai baigsite suvedineti duomenis, iveskite [0] ir spustelekite 'enter': " << endl;
            while (true){
                cin >> paz;
                if (paz == 0) break;
                A.ND.push_back(paz);
                nd++;
            }
        }
        if (nd != 0){
            cout << "Ivertinimui naudoti [v]idurki ar [m]ediana? ";
            cin >> A.vm;
            if (A.vm == "m"){
                sort(A.ND.begin(), A.ND.end());
                vid = Mediana(nd, A.ND);
            }
            else if (A.vm == "v") vid = Vidurkis(nd, A.ND);
        }
    return A;
}
// apdorojami duomenys, susije su egzaminu
void Egzaminas(Studentas &M) {
    string a;
    cout << "Ar studentas laike egzamina? (y/n) ";
    cin >> a;
    if (a == "y"){
        cout << "Ar zinote egzamino rezultata? (y/n) ";
        cin >> a;
        if (a == "n"){
            M.egz = myRandom();
            cout << "Sugeneruotas egzamino rezultatas: " << M.egz << endl;
        }
        else {
            cout << "Iveskite egzamino ivertinima: ";
            cin >> M.egz;
        }
    }
    else M.egz = 0;
}
// i konsole isvedami rezultatai
void outputConsole (vector<Studentas> M, int n){
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
        else if (M[i].vm == "m") cout << setw(19) << left << " " << setw(18) << left << fixed << setprecision(2) << M[i].final << "|" << endl;
    }
    for (int i=0; i<k; i++)
        cout << "-";
}