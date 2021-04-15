#ifndef FILEHEADER_H
#define FILEHEADER_H

#include <fstream>

void generateFile(int n, int nd, string name);
void readFile(list<Studentas> &M, int nd, string t, int ap, void (*vid_med)(Studentas&, int));
void execusionTest(int ap, string title, int nd, string vm, string arGen);
void distinctStudents(list<Studentas> &Kietiakai, int ap, string vm, double &time_taken);
void outputTime(int ap, list<Studentas> &G, string title, string league, string vm);
void outputFile(list<Studentas> &M, string t, string vm);
void Clean(Studentas &A);

#endif