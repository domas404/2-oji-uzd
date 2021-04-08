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
void readFile(deque<string> &split, string t, int ap, double &time_taken){
    auto pr = chrono::high_resolution_clock::now();
    string line;
    stringstream buffer;
    ifstream input(t);
    try{
        if (input.is_open()){
            getline(input, line);
            while(input){
                getline(input, line);
                split.push_back(line);
            }
        }
        else throw(t);
    }
    catch(string t){
        cout << "Neimanoma atidaryti failo pavadinimu \"" << t << "\"" << endl;
    }
    input.close();
    auto pab = chrono::high_resolution_clock::now();
    time_taken = chrono::duration_cast<chrono::nanoseconds>(pab - pr).count();
    time_taken *= 1e-9;
    cout << setw(8) << right << ap << setw(50) << left << " studentu nuskaitymas uztruko: ";
    cout << time_taken << " s" << endl;    
}
// strukturai priskiriamos nuskaitytu duomenu reiksmes
void assignStruct(deque<string> &split, int &nd, deque<Studentas> &M, int ap){
    auto pr = chrono::high_resolution_clock::now();
    Studentas A;
    deque<string>::iterator it = split.begin();
    int p;
    for(it; it!=split.end(); ++it){
        istringstream iss(*it);
        iss >> A.vardas >> A.pavarde;
        for (int i=0; i<10; i++){
            iss >> p;
            A.ND.push_back(p);
        }
        iss >> A.egz;
        AssignVid(A, nd);
        M.push_back(A);
        Clean(A);
        split.pop_front();
    }
    split.clear();
    auto pab = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(pab - pr).count();
    time_taken *= 1e-9;
    // cout << setw(8) << right << ap << setw(50) << left << " studentu skaiciavimai uztruko: ";
    // cout << time_taken << " s" << endl;
}
// skaiciuojamas protingu ir nelabai studentu isvedimo laikas
void outputTime(int ap, deque<Studentas> &G, int size, string title, string league, string vm){
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
void distinctStudents(deque<Studentas> &M, int ap, string vm, double &time_taken){
    auto pr = chrono::high_resolution_clock::now();
    deque<Studentas> Kietiakai;
    deque<Studentas> Varguoliai;
    int size_1=0, size_2=0;
    string p=".\\kietiakai\\kietiakai";
    string t=".\\varguoliai\\varguoliai";
    p += to_string(ap);
    t += to_string(ap);
    deque<Studentas>::iterator it;
    Kietiakai.swap(M);
    it = find_if(Kietiakai.begin(), Kietiakai.end(), isLessThan);
    Varguoliai.assign(it, Kietiakai.end());
    Kietiakai.erase(it, Kietiakai.end());
    M.clear();
    auto pab = chrono::high_resolution_clock::now();
    time_taken = chrono::duration_cast<chrono::nanoseconds>(pab - pr).count();
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
    deque<string> Lines;
    double time_1, time_2, time_3;
    double time=0;
    if (arGen == "y")
        generateFile(ap, nd, title);
    readFile(Lines, title, ap, time_1);
    assignStruct(Lines, nd, M, ap);
    sortStudents(M, ap, time_2);
    distinctStudents(M, ap, vm, time_3);
    M.clear();
    time += time_1 + time_2 + time_3;
    auto pab = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(pab - pr).count();
    time_taken *= 1e-9;
    cout << endl;
    cout << setw(8) << right << ap << setw(50) << left << " irasu testo laikas: ";
    cout << time << " s" << endl;
    cout << endl;
}
// i tekstini faila isvedami rezultatai
void outputFile(deque<Studentas> &M, int n, string t, string vm){
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
    for (deque<Studentas>::iterator it = M.begin(); it!=M.end(); ++it){
        r << setw(p) << left << (*it).vardas << setw(p) << left << (*it).pavarde;
        r << fixed << setprecision(2) << (*it).final << endl;
    }
    r.close();
}
