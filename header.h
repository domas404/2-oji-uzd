#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <random>
#include <time.h>
#include <algorithm>
#include <chrono>

using namespace std;
using hrClock = chrono::high_resolution_clock;

//Saugomi studento duomenys
struct Studentas {
    string vardas, pavarde; // vardas, pavarde
    vector<int> ND;         // namu darbu ivertinimai
    int egz;                // egzamino rezultatas
    string vm;              // ar galutinis pazymys generuojamas su vidurkiu ar mediana
    float final;            // galutinis pazymys
};

double myRandom();
float Final(float vid, float egz);
float Mediana(int nd, vector<int> ND);
float Vidurkis(int nd, vector<int> ND);
void AssignVid(Studentas &A, int nd);
void AssignMed(Studentas &A, int nd);
void sortStudents(vector<Studentas> &M, int ap);
bool wayToSort(Studentas a, Studentas b);

void usingConsole(vector<Studentas> M, Studentas A);
void readName(Studentas &S);
Studentas Namu_darbai(float vid);
void Egzaminas(Studentas &M);
void outputConsole(vector<Studentas> M, int n);

#endif