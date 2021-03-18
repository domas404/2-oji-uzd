#include "header.h"
#include "header_for_files.h"

// nurodomi rikiavimo kriterijai 
bool wayToSort(Studentas a, Studentas b) {
    return a.final < b.final;    // nurodoma rikiuoti pagal varda didejanciai (abeceles tvarka)
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
    float vid;
    if (nd%2==1){
        a = nd/2;
        vid = ND[a];
    }
    else {
        a = nd/2-1;
        b = nd/2;
        vid = (float)(ND[a] + ND[b])/2;
    }
    return vid;
}
// funkcija, skaiciuojanti ivertinimu vidurki
float Vidurkis(int nd, vector<int> ND){
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
void sortStudents(vector<Studentas> &M, int ap){
    clock_t pr, pab;
    pr = clock();
    sort(M.begin(), M.end(), wayToSort);
    pab = clock();
    cout << setw(8) << right << ap << setw(50) << left << " studentu rikiavimas pagal gal. ivert. uztruko: ";
    cout << 1.0 * (pab - pr) / CLOCKS_PER_SEC << " s" << endl;
}