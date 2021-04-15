#include "header.h"
#include "fileHeader.h"

// studentu skirstymas i dvi grupes (kietiakus ir varguolius)
void distinctStudents(vector<Studentas> &Kietiakai, vector<Studentas> &Varguoliai, int ap, string vm, double &time_taken){
    auto pr = chrono::high_resolution_clock::now();
    vector<Studentas>::iterator it1;
    it1 = find_if(Kietiakai.begin(), Kietiakai.end(), isLessThan);
    Varguoliai.assign(it1, Kietiakai.end());
    Kietiakai.resize(Kietiakai.size()-Varguoliai.size());
    auto pab = chrono::high_resolution_clock::now();
    time_taken = chrono::duration_cast<chrono::nanoseconds>(pab - pr).count();
    time_taken *= 1e-9;
    cout << setw(8) << right << ap << setw(50) << left << " studentu skirstymas i dvi grupes uztruko: ";
    cout << fixed << time_taken << setprecision(6) << " s" << endl;
    string p=".\\kietiakai\\kietiakai";
    string t=".\\varguoliai\\varguoliai";
    p += to_string(ap);
    t += to_string(ap);

    outputTime(ap, Kietiakai, p+".txt", " kietiaku", vm);
    Kietiakai.clear();
    outputTime(ap, Varguoliai, t+".txt", " varguoliu", vm);
    Varguoliai.clear();
}
