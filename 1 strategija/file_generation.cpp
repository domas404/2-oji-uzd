#include "header.h"
#include "fileHeader.h"

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