#include "header.h"
#include "fileHeader.h"

// rusiuojami vector elementai naudojant partition
void partitionStudents(vector<Studentas> &M, vector<Studentas>::iterator &it, int ap){
    auto pr = chrono::high_resolution_clock::now();
    it = partition(M.begin(), M.end(), isLessThan);
    auto pab = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(pab - pr).count();
    time_taken *= 1e-9;
    cout << setw(8) << right << ap << setw(50) << left << " studentu rusiavimas pagal gal. ivert. uztruko: ";
    cout << time_taken << " s" << endl;
}
// rusiuojami vector elementai
void sortStudents(vector<Studentas> &M, int ap){
    auto pr = chrono::high_resolution_clock::now();
    sort(M.begin(), M.end(), wayToSort);
    auto pab = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(pab - pr).count();
    time_taken *= 1e-9;
    cout << setw(8) << right << ap << setw(50) << left << " studentu rikiavimas pagal gal. ivert. uztruko: ";
    cout << time_taken << " s" << endl;
}
// rusiuojami deque elementai
void sortStudents(deque<Studentas> &M, int ap){
    auto pr = chrono::high_resolution_clock::now();
    sort(M.begin(), M.end(), wayToSort);
    auto pab = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(pab - pr).count();
    time_taken *= 1e-9;
    cout << setw(8) << right << ap << setw(50) << left << " studentu rikiavimas pagal gal. ivert. uztruko: ";
    cout << time_taken << " s" << endl;
}
// rusiuojami list elementai
void sortStudents(list<Studentas> &M, int ap){
    auto pr = chrono::high_resolution_clock::now();
    M.sort(wayToSort);
    auto pab = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(pab - pr).count();
    time_taken *= 1e-9;
    cout << setw(8) << right << ap << setw(50) << left << " studentu rikiavimas pagal gal. ivert. uztruko: ";
    cout << time_taken << " s" << endl;
}