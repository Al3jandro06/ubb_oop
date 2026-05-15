#ifndef LAB05_OOP_OPERATIONS_H
#define LAB05_OOP_OPERATIONS_H
#include "NumarComplex.h"

void citire(int &n, NumarComplex* &v);
void afisare(int n, NumarComplex *v);
NumarComplex entitateMaxima(int n, NumarComplex *v);
void entitatiCadran1(int n, NumarComplex *v, int &l, NumarComplex* &rez);
void secventaEgale(int n, NumarComplex *v, int &l, NumarComplex* &rez);
void meniu();
#endif //LAB05_OOP_OPERATIONS_H