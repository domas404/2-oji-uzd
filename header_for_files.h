#ifndef HEADER_FOR_FILES_H
#define HEADER_FOR_FILES_H

#include <fstream>

void generateFile(int n, int nd, string name);
void readFile(vector<Studentas> &M, int nd, string t, string vm);
void execusionTest(int ap, string title, string result, int nd, string vm);
void distinctStudents(vector<Studentas> &M, int ap, string vm);
void outputTime(int ap, vector<Studentas> &G, int size, string title, string league, string vm);
void outputFile(vector<Studentas> &M, int n, string t, string vm);
void Clean(Studentas &A);

#endif
