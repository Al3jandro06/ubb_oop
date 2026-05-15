#include <iostream>
#include "operations.h"
using namespace std;

void citire(int &n, NumarComplex* &v) {
    cout<<"Introduceti numarul de elemente: ";
    cin>>n;
    v = new NumarComplex[n];
    cout<<"Introduceti elementele:"<<'\n';
    for(int i=0; i<n; i++) {
        double real, imaginar;
        cout<<"Parte reala = ";
        cin>>real;
        cout<<"Parte imaginara = ";
        cin>>imaginar;
        v[i].setReal(real);
        v[i].setImaginar(imaginar);
    }
}

void afisare(int n, NumarComplex* v) {
    if (n==0)
        cout<<"Nu exista elemente in sir"<<'\n';
    for (int i=0; i<n; i++) {
        cout<<v[i].toString()<<'\n';
    }
}

NumarComplex entitateMaxima(int n, NumarComplex *v){
    NumarComplex maxv(0,0);
    for (int i=0; i<n; i++) {
        if (v[i].absolute() > maxv.absolute())
            maxv = v[i];
    }
    return maxv;
}

void entitatiCadran1(int n, NumarComplex *v, int &l, NumarComplex* &rez) {
    l = 0;
    rez = new NumarComplex[n];
    for (int i=0; i<n; i++) {
        if (v[i].getReal() > 0 && v[i].getImaginar() > 0) {
            rez[l++] = v[i];
        }
    }
}

void secventaEgale(int n, NumarComplex *v, int &l, NumarComplex* &rez) {
    int lc, lmax, poz;
    lc = lmax = 0;
    poz = -1;
    rez = new NumarComplex[n];
    for (int i = 1; i < n; i++) {
        if (v[i]==v[i-1])
            lc++;
        else {
            if (lc > lmax) {
                lmax = lc;
                poz = i-lc;
            }
            lc = 1;
        }
    }
    if (lc > lmax) {
        lmax = lc;
        poz = n - lc;
    }
    l = lmax;
    for (int i = 0; i < l; i++)
        rez[i] = v[poz+i];
}

void meniu() {
    cout<<"====MENIU===="<<'\n';
    cout<<"1.Citire entitati"<<'\n';
    cout<<"2.Afisare entitati"<<'\n';
    cout<<"3.Afisare entitate cea mai mare"<<'\n';
    cout<<"4.Afisare entitati aflate in cadranul I"<<'\n';
    cout<<"5.Afisare secventa maxima de elemente egale"<<'\n';
    cout<<"6.Iesire aplicatie"<<'\n';
}