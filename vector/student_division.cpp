#include "header.h"
#include "fileHeader.h"

// studentu skirstymas i dvi grupes (kietiakus ir varguolius)
void distinctStudents(vector<Studentas> &Kietiakai, vector<Studentas> &Varguoliai, int ap, string vm, double &time_taken){
    auto pr = chrono::high_resolution_clock::now();
    //vector<Studentas> Varguoliai;
    vector<Studentas>::iterator it1;
    //cout << "ok1" << endl;
    it1 = find_if(Kietiakai.begin(), Kietiakai.end(), isLessThan);
    //cout << "ok2" << endl;
    //Varguoliai.reserve(ap*0.5);
    //cout << "ok3" << endl;
    Varguoliai.assign(it1, Kietiakai.end());
    //cout << "ok4" << endl;
    Kietiakai.resize(Kietiakai.size()-Varguoliai.size());
    //cout << "ok5" << endl;

    // vector<Studentas>::iterator it2 = Kietiakai.end()-1;
    // for(it2; it2!=it1; --it2){
    //     Varguoliai.push_back(*it2);
    //     Kietiakai.pop_back();
        //++size_1;
        //if (size_1%100000==0) cout << size_1 << endl;
    //}
    //M.erase(M.begin(), M.begin()+size_1);
    //Varguoliai.swap(M);

    
    //Kietiakai.swap(M);
    //M.clear();
    
    //Varguoliai.assign(it, Kietiakai.end());
    //Varguoliai.size();

    // 
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
    //outputTime(ap, Kietiakai, p+".txt", " studentu", vm);
}