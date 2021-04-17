#include "header.h"
#include "fileHeader.h"

// testuojami veiksmai su tam tikro dydzio studentu sarasu
void testVector(int ap, string title, int nd, string vm, string arGen){
    auto pr = chrono::high_resolution_clock::now();
    vector<Studentas> M;
    M.reserve(ap);
    if (arGen == "y")
        generateFile(ap, nd, title);
    if(vm == "v")
        readFile(M, nd, title, ap, &Vidurkis);
    else
        readFile(M, nd, title, ap, &Mediana);
    distinctStudents(M, ap, vm);
    auto pab = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(pab - pr).count();
    time_taken *= 1e-9;
    cout << endl;
    cout << setw(8) << right << ap << setw(50) << left << " irasu testo laikas: ";
    cout << time_taken << " s" << endl;
    cout << endl;
}
// testuojami veiksmai su tam tikro dydzio studentu sarasu
void testDeque(int ap, string title, int nd, string vm, string arGen){
    auto pr = chrono::high_resolution_clock::now();
    deque<Studentas> M;
    if (arGen == "y")
        generateFile(ap, nd, title);
    if(vm == "v")
        readFile(M, nd, title, ap, &Vidurkis);
    else
        readFile(M, nd, title, ap, &Mediana);
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
// testuojami veiksmai su tam tikro dydzio studentu sarasu
void testList(int ap, string title, int nd, string vm, string arGen){
    auto pr = chrono::high_resolution_clock::now();
    list<Studentas> M;
    if (arGen == "y")
        generateFile(ap, nd, title);
    if(vm == "v")
        readFile(M, nd, title, ap, &Vidurkis);
    else
        readFile(M, nd, title, ap, &Mediana);
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