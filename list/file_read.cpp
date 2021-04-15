#include "header.h"
#include "fileHeader.h"

// isvalomi tarpinio strukturos kintamojo duomenys
void Clean(Studentas &A){
    A.vardas="";
    A.pavarde="";
    A.ND.clear();
    A.egz=0;
}
// duomenu nuskaitymas is failo
void readFile(list<Studentas> &M, int nd, string t, int ap, void (*vid_med)(Studentas&, int)){
    auto pr = chrono::high_resolution_clock::now();
    ifstream input(t);
    int p;
    string line;
    Studentas A;
    try{
        if (input.is_open()){
            getline(input, line);
            while(!input.eof()){
                getline(input, line);
                istringstream iss(line);
                iss >> A.vardas >> A.pavarde;
                for (int i=0; i<nd; i++){
                    iss >> p;
                    A.ND.push_back(p);
                }
                iss >> A.egz;
                (*vid_med)(A, nd);
                M.push_back(A);
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