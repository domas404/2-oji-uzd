#include "header.h"
#include "header_for_files.h"

int main(){
    Studentas *M = new Studentas[nmax];
    bool repeat = true; // ciklas kartojamas, kol igis reiksme false
    int j=0;            // studento indeksas
    float vid=0;        // namu darbu vidurkis
    string a, b;        // tarpiniai kintamieji, igyjantys viena is dvieju reiksmiu, pateiktu naudotojui pvz. (y/n)
    int nd, ap=0;       // nd - namu darbu ivertinimu kiekis, ap - studentu skaicius
    cout << "Norite duomenis nuskaityti is tekstinio [f]ailo ar [k]onsoles: ";
    cin >> b;
    cin.ignore();
    if (b == "f"){
        cout << "Duomenu failas jau [e]gzistuoja, ar [s]ugeneruoti? ";
        cin >> a;
        if (a == "e")
            openFile(nd, ap, M);
        else if (a == "s")
            createFile(nd, ap, M);
        Calculate(M, ap, nd);
        clock_t pradzia1, pabaiga1;
        pradzia1 = clock();
        outputFile(M, ap);
        pabaiga1 = clock();
        cout << setw(45) << left << "Duomenu irasymas i tekstini faila uztruko: ";
        cout << 1.0 * (pabaiga1 - pradzia1) / CLOCKS_PER_SEC << " s" << endl;
    }
    else if (b == "k") {
        do {
            readName(M[j]);
            Namu_darbai(M[j], vid);
            Egzaminas(M[j]);
            M[j].final = Final(vid, M[j].egz);
            sort (M, M+j+1, wayToSort);
            cout << "Ar norite ivesti kito studento duomenis? (y/n) ";
            cin >> a;
            if (a == "n")
                repeat=false;
            else j++;
            vid=0;
            cin.ignore();
        } while (repeat);
        outputConsole(M, j+1);
    }
    delete[] M;
    return 0;
}