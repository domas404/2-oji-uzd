#include "header.h"
#include "header_for_files.h"

int main(int argc, char **argv){
    string vm;
    int nd;
    nd = atoi(argv[1]); // 1 - namu darbu kiekis
    vm = argv[2];       // 2 - naudoti vidurki ar mediana (v/m)
    execusionTest(1000, "kursiokai1000.txt", "rezultatai1000.txt", nd, vm);
    cout << "Press enter to continue";
    cin.ignore();
    execusionTest(10000, "kursiokai10000.txt", "rezultatai10000.txt", nd, vm);
    cout << "Press enter to continue";
    cin.ignore();
    execusionTest(100000, "kursiokai100000.txt", "rezultatai100000.txt", nd, vm);
    cout << "Press enter to continue";
    cin.ignore();
    execusionTest(1000000, "kursiokai1000000.txt", "rezultatai1000000.txt", nd, vm);
    cout << "Press enter to continue";
    cin.ignore();
    execusionTest(10000000, "kursiokai10000000.txt", "rezultatai10000000.txt", nd, vm);
    return 0;
}
