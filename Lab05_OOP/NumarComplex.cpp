#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include "NumarComplex.h"
using namespace std;

NumarComplex::NumarComplex() {
    this->real = 0;
    this->imaginar = 0;
}

NumarComplex::NumarComplex(double real, double imaginar) {
    this->real = real;
    this->imaginar = imaginar;
}

NumarComplex::NumarComplex(const NumarComplex& z) {
    this->real = z.real;
    this->imaginar = z.imaginar;
}

NumarComplex::~NumarComplex() {
    this->real = 0;
    this->imaginar = 0;
}

double NumarComplex::getReal() {
    return this->real;
}

double NumarComplex::getImaginar() {
    return this->imaginar;
}

void NumarComplex::setReal(double real) {
    this->real = real;
}

void NumarComplex::setImaginar(double imaginar) {
    this->imaginar = imaginar;
}

NumarComplex& NumarComplex::operator=(const NumarComplex& z) {
    if (this != &z) {
        this->real = z.real;
        this->imaginar = z.imaginar;
    }
    return *this;
}

char* NumarComplex::toString() {
    char* repr = new char[50];
    string aux;
    if (this->imaginar > 0)
        aux = to_string(this->real) + "+" + to_string(this->imaginar) + "i";
    else if (this->imaginar < 0)
        aux = to_string(this->real)  + to_string(this->imaginar) + "i";
    else
        aux = to_string(this->real);
    strcpy(repr, aux.c_str());
    return repr;
}

bool NumarComplex::operator==(const NumarComplex & z) {
    return (this->real == z.real && this->imaginar == z.imaginar);
}

NumarComplex NumarComplex::operator+(const NumarComplex & z) {
    return NumarComplex(this->real + z.real, this->imaginar + z.imaginar);
}

NumarComplex NumarComplex::operator-(const NumarComplex & z) {
    return NumarComplex(this->real - z.real, this->imaginar - z.imaginar);
}

NumarComplex NumarComplex::operator*(const NumarComplex & z) {
    return NumarComplex(this->real * z.real - this->imaginar * z.imaginar, this->real * z.imaginar + this->imaginar * z.real);
}

double NumarComplex::absolute() {
    return sqrt(this->real * this->real + this->imaginar * this->imaginar);
}

NumarComplex NumarComplex::conjugate() {
    return NumarComplex(this->real, -this->imaginar);
}