#include "header.h"
#include "header_for_files.h"

// funkcija  sugeneruojanti ir irasanti studentu duomenis i tekstini faila
void generateFile(int n, int nd, string name){
    auto pr = chrono::high_resolution_clock::now();
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
    auto pab = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(pab - pr).count();
    time_taken *= 1e-9;
    cout << setw(8) << right << n << setw(50) << left << " studentu saraso generavimas uztruko: ";
    cout << time_taken << " s" << endl;
}
// isvalomi tarpinio strukturos kintamojo duomenys
void Clean(Studentas &A){
    A.vardas="";
    A.pavarde="";
    A.ND.clear();
    A.egz=0;
}
// nuskaitomi duomenys is tekstinio failo
void readFile(deque<Studentas> &M, int nd, string t, string vm){
    auto pr = chrono::high_resolution_clock::now();
    int ap=0;
    ifstream input(t);
    int p;
    string line;
    int i=0;
    Studentas A;
    try{
        if (input.is_open()){
            getline(input, line);
            while(getline(input, line)){
                istringstream iss(line);
                iss >> A.vardas >> A.pavarde;
                for (int j=0; j<nd; j++){
                    iss >> p;
                    A.ND.push_back(p);
                }
                iss >> A.egz;
                // if (vm == "v")
                    AssignVid(A, nd);
                // else if (vm == "m")
                //     AssignMed(A, nd);
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
    auto pab = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(pab - pr).count();
    time_taken *= 1e-9;
    cout << setw(8) << right << ap << setw(50) << left << " studentu nuskaitymas ir skaiciavimai uztruko: ";
    cout << time_taken << " s" << endl;
}
// skaiciuojamas protingu ir nelabai studentu isvedimo laikas
void outputTime(int ap, vector<Studentas> &G, int size, string title, string league, string vm){
    league += " rasymas i tekstini faila uztruko: ";
    auto pr = chrono::high_resolution_clock::now();
    outputFile(G, size, title, vm);
    auto pab = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(pab - pr).count();
    time_taken *= 1e-9;
    cout << setw(8) << right << ap << setw(50) << left << league;
    cout << time_taken << " s" << endl;
}
// studentu skirstymas i dvi grupes (kietiakus ir varguolius)
void distinctStudents(deque<Studentas> &M, int ap, string vm){
    auto pr = chrono::high_resolution_clock::now();
    deque<Studentas> Kietiakai;
    deque<Studentas> Varguoliai;
    // Kietiakai.reserve(ap*0.7);
    int size_1=0, size_2=0;
    string p=".\\kietiakai\\kietiakai";
    string t=".\\varguoliai\\varguoliai";
    p += to_string(ap);
    t += to_string(ap);
    int j=0;
    while (M[j].final >= 5){
        Kietiakai.push_back(M[j]);
        ++size_1;
        ++j;
    }
    M.erase(M.begin(), M.begin()+size_1);
    cout << M[0].vardas << " " << M[0].final << endl;
    Varguoliai.assign(M.begin(), M.end()-1);
    // Varguoliai.swap(M);
    size_2 = Varguoliai.size();
    auto pab = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(pab - pr).count();
    time_taken *= 1e-9;
    cout << setw(8) << right << ap << setw(50) << left << " studentu skirstymas i dvi grupes uztruko: ";
    cout << fixed << time_taken << setprecision(6) << " s" << endl;

    // outputTime(ap, Kietiakai, size_1, p+".txt", " kietiaku", vm);
    Kietiakai.clear();
    // outputTime(ap, Varguoliai, size_2, t+".txt", " varguoliu", vm);
    Varguoliai.clear();
}
// testuojami veiksmai su tam tikro dydzio studentu sarasu
void execusionTest(int ap, string title, int nd, string vm, string arGen){
    auto pr = chrono::high_resolution_clock::now();
    deque<Studentas> M;
    // M.reserve(ap);
    if (arGen == "y")
        generateFile(ap, nd, title);
    readFile(M, nd, title, vm);
    sortStudents(M, ap);
    distinctStudents(M, ap, vm);
    M.clear();
    auto pab = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(pab - pr).count();
    time_taken *= 1e-9;
    cout << endl;
    cout << setw(8) << right << ap << setw(50) << left << " irasu testo laikas: ";
    cout << time_taken << " s" << endl;
    cout << endl;
}
// i tekstini faila isvedami rezultatai
void outputFile(vector<Studentas> &M, int n, string t, string vm){
    ofstream r(t);
    int k=57, p=18;
    r << setw(p) << left << "Vardas" << setw(p) << left << "Pavarde";
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