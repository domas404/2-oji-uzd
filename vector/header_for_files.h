#ifndef HEADER_FOR_FILES_H
#define HEADER_FOR_FILES_H

#include <fstream>

void generateFile(int n, int nd, string name);
void readFile(deque<string> &split, string t, int ap, double &time_taken);
void execusionTest(int ap, string title, int nd, string vm, string arGen);
void distinctStudents(vector<Studentas> &M, int ap, string vm, double &time_taken);
void outputTime(int ap, vector<Studentas> &G, int size, string title, string league, string vm);
void outputFile(vector<Studentas> &M, int n, string t, string vm);
void Clean(Studentas &A);

#endif