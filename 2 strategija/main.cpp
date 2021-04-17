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
    cout << "I kuri konteineri talpinti duomenis? "<< endl;
    cout << "[1] vector\n[2] deque\n[3] list\n";
    int type;
    cin >> type;
    switch(type){
        case 1:
            testVector(1000, ".\\kursiokai\\kursiokai1000.txt", nd, vm, arGen);
            testVector(10000, ".\\kursiokai\\kursiokai10000.txt", nd, vm, arGen);
            testVector(100000, ".\\kursiokai\\kursiokai100000.txt", nd, vm, arGen);
            testVector(1000000, ".\\kursiokai\\kursiokai1000000.txt", nd, vm, arGen);
            testVector(10000000, ".\\kursiokai\\kursiokai10000000.txt", nd, vm, arGen);
            break;
        case 2:
            testDeque(1000, ".\\kursiokai\\kursiokai1000.txt", nd, vm, arGen);
            testDeque(10000, ".\\kursiokai\\kursiokai10000.txt", nd, vm, arGen);
            testDeque(100000, ".\\kursiokai\\kursiokai100000.txt", nd, vm, arGen);
            testDeque(1000000, ".\\kursiokai\\kursiokai1000000.txt", nd, vm, arGen);
            testDeque(10000000, ".\\kursiokai\\kursiokai10000000.txt", nd, vm, arGen);
            break;
        case 3:
            testList(1000, ".\\kursiokai\\kursiokai1000.txt", nd, vm, arGen);
            testList(10000, ".\\kursiokai\\kursiokai10000.txt", nd, vm, arGen);
            testList(100000, ".\\kursiokai\\kursiokai100000.txt", nd, vm, arGen);
            testList(1000000, ".\\kursiokai\\kursiokai1000000.txt", nd, vm, arGen);
            testList(10000000, ".\\kursiokai\\kursiokai10000000.txt", nd, vm, arGen);
            break;
    }
    return 0;
}