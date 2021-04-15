#include "header.h"
#include "fileHeader.h"

// testuojami veiksmai su tam tikro dydzio studentu sarasu
void execusionTest(int ap, string title, int nd, string vm, string arGen){
    auto pr = chrono::high_resolution_clock::now();
    list<Studentas> M;
    if (arGen == "y")
        generateFile(ap, nd, title);
    if(vm == "v")
        readFile(M, nd, title, ap, &AssignVid);
    else
        readFile(M, nd, title, ap, &AssignMed);
    sortStudents(M, ap, time_2);
    distinctStudents(M, ap, vm, time_3);

    auto pab = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(pab - pr).count();
    time_taken *= 1e-9;
    cout << endl;
    cout << setw(8) << right << ap << setw(50) << left << " irasu testo laikas: ";
    cout << time_taken << " s" << endl;
    cout << endl;
}
