#include "header.h"

// atsitiktiniu skaiciu generavimo funkcija
double myRandom(){
    static mt19937 mt(static_cast<long unsigned int>(hrClock::now().time_since_epoch().count()));
    static uniform_int_distribution<int> dist(1, 10);
    return dist(mt);
}
// nurodomi rikiavimo kriterijai
bool wayToSort(Studentas a, Studentas b) {
    return a.vardas < b.vardas;    // nurodoma rikiuoti pagal varda didejanciai (abeceles tvarka)
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
// skaiciuojamas galutinis ivertinimas
float Final(float vid, float egz){
    return ((vid)*0.4 + (egz*0.6));
}
// funkcija, nuskaitanti studento varda ir pavarde
void readName(Studentas &S){
    cout << "Iveskite studento varda: ";
    getline(cin, S.vardas);
    cout << "Iveskite studento pavarde: ";
    getline(cin, S.pavarde);
}
// funkcija, apdorojanti visus duomenis susijusius su namu darbais
void Namu_darbai(Studentas &M, float &vid){
    int nd=0, ndc;  // nd - atliktu namu darbu kiekis, ndc - nd kopija
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
                    for (int i=0; i<nd; i++){
                        M.ND.push_back(myRandom());
                        cout << M.ND[i] << " ";
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
                                M.ND.push_back(paz);
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
        else if (M[i].vm == "m") cout << setw(19) << left << " " << setw(18) << left << fixed << setprecision(2) << M[i].final << "|" << endl;
    }
    for (int i=0; i<k; i++)
        cout << "-";
}