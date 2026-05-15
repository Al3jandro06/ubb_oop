#include "RepoCheltuieli.h"

void RepoCheltuieli::resize() {
    this->capacity *= 2;
    Cheltuiala* newArr = new Cheltuiala[this->capacity];
    for (int i = 0; i < this->size; i++)
        newArr[i] = this->cheltuieli[i];
    delete[] this->cheltuieli;
    this->cheltuieli = newArr;
}

int RepoCheltuieli::poz(Cheltuiala &c) {
    for (int i = 0; i < size; i++)
        if (cheltuieli[i] == c)
            return i;
    return -1;
}

RepoCheltuieli::RepoCheltuieli() {
    this->size = 0;
    this->capacity = 10;
    this->cheltuieli = new Cheltuiala[this->capacity];
}

void RepoCheltuieli::addElem(Cheltuiala &c) {
    if (size >= this->capacity)
        resize();
    cheltuieli[size++] = c;
}

bool RepoCheltuieli::update(Cheltuiala &c1, Cheltuiala &c2) {
    int p = poz(c1);
    if (p >= 0) {
        cheltuieli[p] = c2;
        return true;
    }
    return false;
}

bool RepoCheltuieli::findOne(Cheltuiala &c) {
    return poz(c)>=0?true:false;
}

bool RepoCheltuieli::remove(Cheltuiala &c) {
    int p = poz(c);
    if (p >= 0) {
        cheltuieli[p] = cheltuieli[--size];
        return true;
    }
    return false;
}

int RepoCheltuieli::getSize() {
    return this->size;
}

Cheltuiala RepoCheltuieli::getAt(int poz) {
    if (poz >= 0 && poz < this->size)
        return this->cheltuieli[poz];
}

Cheltuiala* RepoCheltuieli::getAll() {
    return this->cheltuieli;
}

RepoCheltuieli::~RepoCheltuieli() {
    this->size = 0;
    if (this->cheltuieli != nullptr)
        delete[] this->cheltuieli;
}
