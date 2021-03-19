#include "header.h"
#include "header_for_files.h"

int main(int argc, char **argv){
    string vm;
    int nd;
    nd = atoi(argv[1]); // 1 - namu darbu kiekis
    vm = argv[2];       // 2 - naudoti vidurki ar mediana (v/m)
    execusionTest(1000, ".\\kursiokai\\kursiokai1000.txt", nd, vm);
    cout << "Press enter to continue";
    cin.ignore();
    execusionTest(10000, ".\\kursiokai\\kursiokai10000.txt", nd, vm);
    cout << "Press enter to continue";
    cin.ignore();
    execusionTest(100000, ".\\kursiokai\\kursiokai100000.txt", nd, vm);
    cout << "Press enter to continue";
    cin.ignore();
    execusionTest(1000000, ".\\kursiokai\\kursiokai1000000.txt", nd, vm);
    cout << "Press enter to continue";
    cin.ignore();
    execusionTest(10000000, ".\\kursiokai\\kursiokai10000000.txt", nd, vm);
    return 0;
}
