#include "header.h"
#include "fileHeader.h"

// studentu skirstymas i dvi grupes (kietiakus ir varguolius) (vector)
void distinctStudents(vector<Studentas> &Kietiakai, int ap, string vm){
    vector<Studentas>::iterator it;
    partitionStudents(Kietiakai, it, ap);
    auto pr = chrono::high_resolution_clock::now();

    vector<Studentas> Varguoliai;
    Varguoliai.assign(it, Kietiakai.end());
    Kietiakai.resize(Kietiakai.size()-Varguoliai.size());

    auto pab = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(pab - pr).count();
    time_taken *= 1e-9;
    cout << setw(8) << right << ap << setw(50) << left << " studentu skirstymas i dvi grupes uztruko: ";
    cout << fixed << time_taken << setprecision(6) << " s" << endl;
    string p=".\\kietiakai\\kietiakai";
    string t=".\\varguoliai\\varguoliai";
    p += to_string(ap);
    t += to_string(ap);

    outputFile(Kietiakai, ap, p+".txt", " kietiaku", vm);
    Kietiakai.clear();
    outputFile(Varguoliai, ap, t+".txt", " varguoliu", vm);
    Varguoliai.clear();
}
// studentu skirstymas i dvi grupes (kietiakus ir varguolius) (deque)
void distinctStudents(deque<Studentas> &Kietiakai, int ap, string vm){
    auto pr = chrono::high_resolution_clock::now();

    deque<Studentas> Varguoliai;
    deque<Studentas>::iterator it1;
    it1 = find_if(Kietiakai.begin(), Kietiakai.end(), isLessThan);
    Varguoliai.assign(it1, Kietiakai.end());
    Kietiakai.resize(Kietiakai.size()-Varguoliai.size());

    auto pab = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(pab - pr).count();
    time_taken *= 1e-9;
    cout << setw(8) << right << ap << setw(50) << left << " studentu skirstymas i dvi grupes uztruko: ";
    cout << fixed << time_taken << setprecision(6) << " s" << endl;
    string p=".\\kietiakai\\kietiakai";
    string t=".\\varguoliai\\varguoliai";
    p += to_string(ap);
    t += to_string(ap);

    outputFile(Kietiakai, ap, p+".txt", " kietiaku", vm);
    Kietiakai.clear();
    outputFile(Varguoliai, ap, t+".txt", " varguoliu", vm);
    Varguoliai.clear();
}
// studentu skirstymas i dvi grupes (kietiakus ir varguolius) (list)
void distinctStudents(list<Studentas> &Kietiakai, int ap, string vm){
    auto pr = chrono::high_resolution_clock::now();

    list<Studentas> Varguoliai;
    list<Studentas>::iterator it1;
    it1 = find_if(Kietiakai.begin(), Kietiakai.end(), isLessThan);
    Varguoliai.assign(it1, Kietiakai.end());
    Kietiakai.resize(Kietiakai.size()-Varguoliai.size());

    auto pab = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(pab - pr).count();
    time_taken *= 1e-9;
    cout << setw(8) << right << ap << setw(50) << left << " studentu skirstymas i dvi grupes uztruko: ";
    cout << fixed << time_taken << setprecision(6) << " s" << endl;
    string p=".\\kietiakai\\kietiakai";
    string t=".\\varguoliai\\varguoliai";
    p += to_string(ap);
    t += to_string(ap);

    outputFile(Kietiakai, ap, p+".txt", " kietiaku", vm);
    Kietiakai.clear();
    outputFile(Varguoliai, ap, t+".txt", " varguoliu", vm);
    Varguoliai.clear();
}