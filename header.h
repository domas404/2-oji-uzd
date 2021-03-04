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

const int nmax=10000000;    //maksimalus studentu skaicius

//Saugomi studento duomenys
struct Studentas {
    string vardas, pavarde; // vardas, pavarde
    vector<int> ND;         // namu darbu ivertinimai
    int egz;                // egzamino rezultatas
    string vm;              // ar galutinis pazymys generuojamas su vidurkiu ar mediana
    float final;            // galutinis pazymys
};

double myRandom();
void readName(Studentas &S);
float Mediana(int nd, vector<int> ND);
float Vidurkis(int nd, vector<int> ND);
float Final(float vid, float egz);
void Namu_darbai(Studentas &M, float &vid);
void Egzaminas(Studentas &M);
void outputConsole (Studentas M[], int n);

#endif