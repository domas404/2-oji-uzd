#include "header.h"
#include "fileHeader.h"

// isvalomi tarpinio strukturos kintamojo duomenys
void Clean(Studentas &A){
    A.vardas="";
    A.pavarde="";
    A.ND.clear();
    A.egz=0;
}
// nuskaitomi duomenys is tekstinio failo
//template <typename T>
// void readFile(deque<string> &split, string t, int ap, double &time_taken){
//     auto pr = chrono::high_resolution_clock::now();
//     string line;
//     stringstream buffer;
//     ifstream input(t);
//     try{
//         if (input.is_open()){
//             getline(input, line);
//             while(input){
//                 getline(input, line);
//                 split.push_back(line);
//             }
//         }
//         else throw(t);
//     }
//     catch(string t){
//         cout << "Neimanoma atidaryti failo pavadinimu \"" << t << "\"" << endl;
//     }
//     input.close();
//     auto pab = chrono::high_resolution_clock::now();
//     time_taken = chrono::duration_cast<chrono::nanoseconds>(pab - pr).count();
//     time_taken *= 1e-9;
//     cout << setw(8) << right << ap << setw(50) << left << " studentu nuskaitymas uztruko: ";
//     cout << time_taken << " s" << endl;    
// }
void readFile(vector<Studentas> &M, int nd, string t, int ap, void (*vid_med)(Studentas&, int)){
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
// strukturai priskiriamos nuskaitytu duomenu reiksmes
// void assignStruct(deque<string> &split, int &nd, vector<Studentas> &M, int ap, void (*vid_med)(Studentas&, int)){
//     auto pr = chrono::high_resolution_clock::now();
//     Studentas A;
//     int p;
//     int a=0;
//     deque<string>::iterator it = split.begin();
//     for(it; it!=split.end(); ++it){
//         istringstream iss(*it);
//         iss >> A.vardas >> A.pavarde;
//         for (int i=0; i<10; i++){
//             iss >> p;
//             A.ND.push_back(p);
//         }
//         iss >> A.egz;
//         (*vid_med)(A, nd);
//         M.push_back(A);
//         Clean(A);
//         split.pop_front();
//         ++a;
//         if(a==ap) break;
//     }
//     split.clear();
//     auto pab = chrono::high_resolution_clock::now();
//     double time_taken = chrono::duration_cast<chrono::nanoseconds>(pab - pr).count();
//     time_taken *= 1e-9;
//     cout << setw(8) << right << ap << setw(50) << left << " studentu skaiciavimai uztruko: ";
//     cout << time_taken << " s" << endl;
// }