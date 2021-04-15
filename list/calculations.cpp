#include "header.h"
#include "fileHeader.h"

// nurodomi rikiavimo kriterijai 
bool wayToSort(const Studentas &a, const Studentas &b) {
    return a.final > b.final;    // nurodoma rikiuoti pagal varda didejanciai (abeceles tvarka)
}
// ieskoma ribos, kuri skiria 'kietiakus' ir 'varguolius'
bool isLessThan(Studentas &i){
    return(i.final < 5);
}
// atsitiktiniu skaiciu generavimo funkcija
double myRandom(){
    static mt19937 mt(static_cast<long unsigned int>(hrClock::now().time_since_epoch().count()));
    static uniform_int_distribution<int> dist(1, 10);
    return dist(mt);
}
// skaiciuojamas galutinis ivertinimas
float Final(float vid, float egz){
    return ((vid)*0.4 + (egz*0.6));
}
// funkcija, skaiciuojanti ivertinimu mediana
float Mediana(int nd, vector<int> ND){
    int a, b;
    float med;
    if (nd%2==1){
        a = nd/2;
        med = ND[a];
    }
    else {
        a = nd/2-1;
        b = nd/2;
        med = (float)(ND[a] + ND[b])/2;
    }
    return med;
}
// funkcija, skaiciuojanti ivertinimu vidurki
float Vidurkis(int &nd, vector<int> &ND){
    int suma=0;
    for (int i=0; i<nd; i++){
        suma += ND[i];
    }
    return (float)suma/nd;
}
// funkcija, kuri kreipiasi i vidurkio skaic. funkcija
void AssignVid(Studentas &A, int nd){
    float vid=0;
    vid = Vidurkis(nd, A.ND);
    A.final = Final(vid, A.egz);
}
// funkcija, kuri kreipiasi i medianos skaic. funkcija
void AssignMed(Studentas &A, int nd){
    float med=0;
    sort(A.ND.begin(), A.ND.end());
    med = Mediana(nd, A.ND);
    A.final = Final(med, A.egz);
}
// rusiuojami studentai
void sortStudents(list<Studentas> &M, int ap){
    auto pr = chrono::high_resolution_clock::now();
    M.sort(wayToSort);
    auto pab = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(pab - pr).count();
    time_taken *= 1e-9;
    cout << setw(8) << right << ap << setw(50) << left << " studentu rikiavimas pagal gal. ivert. uztruko: ";
    cout << time_taken << " s" << endl;
}
