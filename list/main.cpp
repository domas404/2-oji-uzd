#include "header.h"
#include "fileHeader.h"

int main(int argc, char **argv){
    string vm;
    int nd;
    nd = atoi(argv[1]); // 1 - namu darbu kiekis
    vm = argv[2];       // 2 - naudoti vidurki ar mediana (v/m)
    string arGen;
    cout << "Ar generuoti naujus sarasus? [y/n] ";
    cin >> arGen;
    
    execusionTest(1000, ".\\kursiokai\\kursiokai1000.txt", nd, vm, arGen);
    execusionTest(10000, ".\\kursiokai\\kursiokai10000.txt", nd, vm, arGen);
    execusionTest(100000, ".\\kursiokai\\kursiokai100000.txt", nd, vm, arGen);
    execusionTest(1000000, ".\\kursiokai\\kursiokai1000000.txt", nd, vm, arGen);
    execusionTest(10000000, ".\\kursiokai\\kursiokai10000000.txt", nd, vm, arGen);

    return 0;
}