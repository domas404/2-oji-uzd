#ifndef FILEHEADER_H
#define FILEHEADER_H

#include <fstream>

void generateFile(int n, int nd, string name);

void testVector(int ap, string title, int nd, string vm, string arGen);
void testDeque(int ap, string title, int nd, string vm, string arGen);
void testList(int ap, string title, int nd, string vm, string arGen);

void readFile(vector<Studentas> &M, int nd, string t, int ap, float (*vid_med)(int, vector<int>&));
void readFile(deque<Studentas> &M, int nd, string t, int ap, float (*vid_med)(int, vector<int>&));
void readFile(list<Studentas> &M, int nd, string t, int ap, float (*vid_med)(int, vector<int>&));

void distinctStudents(vector<Studentas> &Kietiakai, int ap, string vm);
void distinctStudents(deque<Studentas> &Kietiakai, int ap, string vm);
void distinctStudents(list<Studentas> &Kietiakai, int ap, string vm);

void outputFile(vector<Studentas> &M, int ap, string title, string league, string vm);
void outputFile(deque<Studentas> &M, int ap, string title, string league, string vm);
void outputFile(list<Studentas> &M, int ap, string title, string league, string vm);

#endif