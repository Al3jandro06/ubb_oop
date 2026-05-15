#ifndef LAB06_OOP_OPERATIONS_H
#define LAB06_OOP_OPERATIONS_H
#include "NumarComplex.h"
#include <vector>
using namespace std;
void citire(vector<NumarComplex> &v);
void afisare(vector<NumarComplex> &v);
NumarComplex entitateMaxima(vector<NumarComplex> &v);
void entitatiCadran1(vector<NumarComplex> &v, vector<NumarComplex> &rez);
void secventaEgale(vector<NumarComplex> &v, vector<NumarComplex> &rez);
void meniu();
#endif //LAB06_OOP_OPERATIONS_H