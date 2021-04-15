#include "header.h"
#include "fileHeader.h"

// skaiciuojamas protingu ir nelabai studentu isvedimo laikas
void outputTime(int ap, deque<Studentas> &G, string title, string league, string vm){
    league += " rasymas i tekstini faila uztruko: ";
    auto pr = chrono::high_resolution_clock::now();
    outputFile(G, title, vm);
    auto pab = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(pab - pr).count();
    time_taken *= 1e-9;
    cout << setw(8) << right << ap << setw(50) << left << league;
    cout << time_taken << " s" << endl;
}
// i tekstini faila isvedami rezultatai
void outputFile(deque<Studentas> &M, string t, string vm){
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