#include "Cheltuiala.h"
#include <cstring>
#include <stdlib.h>

Cheltuiala::Cheltuiala() {
    nrAp = 0;
    suma = 0;
    tip = nullptr;
}

Cheltuiala::Cheltuiala(int nr, int s, char* t) {
    nrAp = nr;
    suma = s;
    tip = new char[strlen(t) + 1];
    strcpy(tip, t);
}

Cheltuiala::Cheltuiala(const Cheltuiala &c) {
    nrAp = c.nrAp;
    suma = c.suma;
    tip = new char[strlen(c.tip) + 1];
    strcpy(tip, c.tip);
}

Cheltuiala& Cheltuiala::operator=(const Cheltuiala &c) {
    if (this != &c) {
        if (this->tip != nullptr) {
            delete[] this->tip;
        }
        nrAp = c.nrAp;
        suma = c.suma;
        tip = new char[strlen(c.tip) + 1];
        strcpy(tip, c.tip);
    }
    return *this;
}

int Cheltuiala::getNrAp() {
    return nrAp;
}

void Cheltuiala::setNrAp(int nr) {
    nrAp = nr;
}

int Cheltuiala::getSuma() {
    return suma;
}

void Cheltuiala::setSuma(int s) {
    suma = s;
}

char* Cheltuiala::getTip() {
    return tip;
}

void Cheltuiala::setTip(char *t) {
    if (this->tip != nullptr)
        delete[] this->tip;
    this->tip = new char[strlen(t) + 1];
    strcpy(this->tip, t);
}

char * Cheltuiala::toString() {
    char *s = new char[strlen(this->tip) + 10];
    char *aux = new char[3];
    itoa(this->nrAp, aux, 10);
    strcpy(s,aux);
    strcat(s, " ");
    delete[] aux;
    aux = new char[5];
    itoa(this->suma, aux, 10);
    strcat(s,aux);
    strcat(s, " ");
    strcat(s,this->tip);
    return s;
}

bool Cheltuiala::operator==(const Cheltuiala &c) {
    return (nrAp == c.nrAp && suma == c.suma && strcmp(c.tip, tip) == 0);
}

Cheltuiala::~Cheltuiala() {
    if (this->tip != nullptr)
        delete[] this->tip;
}


