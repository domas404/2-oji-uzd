#include "header.h"
#include "fileHeader.h"

// nurodomi rikiavimo kriterijai 
bool wayToSort(const Studentas &a, const Studentas &b) {
    return a.final > b.final;    // nurodoma rikiuoti pagal varda didejanciai (abeceles tvarka)
}
// ieskoma ribos, kuri skiria 'kietiakus' ir 'varguolius'
bool isLessThan(Studentas &i){
    return(i.final >= 5);
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
float Mediana(int nd, vector<int> &ND){
    int a, b;
    float med;
    sort(ND.begin(), ND.end());
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
float Vidurkis(int nd, vector<int> &ND){
    int suma=0;
    for (int i=0; i<nd; i++){
        suma += ND[i];
    }
    return (float)suma/nd;
}
