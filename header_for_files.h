#ifndef HEADER_FOR_FILES_H
#define HEADER_FOR_FILES_H

#include <fstream>

void Generate_txt(int n, int nd);
void readFile(Studentas M[], int nd, int &ap, string t);
bool wayToSort(Studentas a, Studentas b);
void Calculate(Studentas M[], int ap, int nd);
void outputFile (Studentas M[], int n);
void openFile(int &nd, int &ap, Studentas M[]);
void createFile(int &nd, int &ap, Studentas M[]);

#endif