#include "tests.h"
#include "NumarComplex.h"
#include <iostream>
#include <cassert>

#include "operations.h"
using namespace std;

void testNumarComplex() {
    NumarComplex z(3,4);
    NumarComplex w(-1,2);
    assert(z.getReal() == 3);
    assert(z.getImaginar() == 4);
    assert(w.getReal() == -1);
    assert(w.getImaginar() == 2);
    w.setReal(6);
    assert(w.getReal() == 6);
    w.setImaginar(-3);
    assert(w.getImaginar() == -3);

    NumarComplex z1 = NumarComplex(3,4);
    NumarComplex z2 = NumarComplex(3,4);
    NumarComplex z3 = NumarComplex(2,4);
    assert(z1==z2);
    assert(!(z1==z3));

    NumarComplex m(1,-1);
    NumarComplex n(-2,3);
    NumarComplex t = m + n;
    assert(t.getReal() == -1);
    assert(t.getImaginar() == 2);

    NumarComplex z4 = m - n;
    assert(z4.getReal()==3);
    assert(z4.getImaginar()==-4);

    NumarComplex a(0,1);
    NumarComplex b(0,1);
    NumarComplex c = a*b;
    assert(c.getReal() == -1);
    assert(c.getImaginar() == 0);

    assert(z1.absolute() == 5);

    NumarComplex d = z1.conjugate();
    assert(d.getReal() == 3);
    assert(d.getImaginar() == -4);
}

void testMaxim() {
    NumarComplex* v = new NumarComplex[4];
    v[0] = NumarComplex(1,-1);
    v[1] = NumarComplex(2,3);
    v[2] = NumarComplex(3,4);
    v[3] = NumarComplex(0,1);
    NumarComplex z = entitateMaxima(4,v);
    assert(z.getReal() == 3);
    assert(z.getImaginar() == 4);
    delete[] v;
}

void testCadran1() {
    NumarComplex* v = new NumarComplex[4];
    v[0] = NumarComplex(1,-1);
    v[1] = NumarComplex(2,3);
    v[2] = NumarComplex(3,4);
    v[3] = NumarComplex(0,-1);
    NumarComplex* rez = NULL;
    int l=0;
    entitatiCadran1(4, v, l, rez);
    assert(l == 2);
    assert(rez[0].getReal() == 2);
    assert(rez[0].getImaginar() == 3);
    assert(rez[1].getReal() == 3);
    assert(rez[1].getImaginar() == 4);
    delete[] v;
}

void testSecventaEgale() {
    NumarComplex* v = new NumarComplex[5];
    v[0] = NumarComplex(1,-1);
    v[1] = NumarComplex(2,3);
    v[2] = NumarComplex(2,3);
    v[3] = NumarComplex(2,3);
    v[4] = NumarComplex(0,-1);
    NumarComplex* rez = NULL;
    int l=0;
    secventaEgale(5, v, l, rez);
    assert(l == 3);
    assert(rez[0].getReal() == 2);
    assert(rez[0].getImaginar() == 3);
    assert(rez[1].getReal() == 2);
    assert(rez[1].getImaginar() == 3);
    assert(rez[2].getReal() == 2);
    assert(rez[2].getImaginar() == 3);
    delete[] v;
}

void allTests() {
    testNumarComplex();
    testMaxim();
    testCadran1();
    testSecventaEgale();
    cout<<"All tests passed!"<<endl;
}