#ifndef HEADER_FOR_FILES_H
#define HEADER_FOR_FILES_H

#include <fstream>

void generateFile(int n, int nd, string name);
void readFile(vector<Studentas> &M, int nd, string t, int ap, void (*vid_med)(Studentas&, int));
void assignStruct(deque<string> &split, int &nd, vector<Studentas> &M, int ap, void (*vid_med)(Studentas&, int));
void execusionTest(int ap, string title, int nd, string vm, string arGen);
void distinctStudents(vector<Studentas> &Kietiakai, vector<Studentas> &Varguoliai, int ap, string vm, double &time_taken);
void outputTime(int ap, vector<Studentas> &G, string title, string league, string vm);
void outputFile(vector<Studentas> &M, string t, string vm);
void Clean(Studentas &A);

#endif
