#include "header.h"
#include "fileHeader.h"

// studentu skirstymas i dvi grupes (kietiakus ir varguolius) (vector)
void distinctStudents(vector<Studentas> &M, int ap, string vm){
    auto pr = chrono::high_resolution_clock::now();

    vector<Studentas> Kietiakai;
    vector<Studentas> Varguoliai;
    vector<Studentas>::iterator it;
    it = find_if(M.begin(), M.end(), isLessThan);
    Kietiakai.assign(M.begin(), it);
    Varguoliai.assign(it, M.end());
    M.clear();

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
void distinctStudents(deque<Studentas> &M, int ap, string vm){
    auto pr = chrono::high_resolution_clock::now();

    deque<Studentas> Kietiakai;
    deque<Studentas> Varguoliai;
    deque<Studentas>::iterator it;
    it = find_if(M.begin(), M.end(), isLessThan);
    Kietiakai.assign(M.begin(), it);
    Varguoliai.assign(it, M.end());
    M.clear();

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
void distinctStudents(list<Studentas> &M, int ap, string vm){
    auto pr = chrono::high_resolution_clock::now();

    list<Studentas> Kietiakai;
    list<Studentas> Varguoliai;
    list<Studentas>::iterator it;
    it = find_if(M.begin(), M.end(), isLessThan);
    Kietiakai.assign(M.begin(), it);
    Varguoliai.assign(it, M.end());
    M.clear();

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