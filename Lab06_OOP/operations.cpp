#include "operations.h"
#include <iostream>

void citire(vector<NumarComplex> &v) {
    int n;
    cout<<"Introduceti numarul de elemente: ";
    cin>>n;
    cout<<"Introduceti elementele:"<<'\n';
    for(int i=0; i<n; i++) {
        double real, imaginar;
        cout<<"Parte reala = ";
        cin>>real;
        cout<<"Parte imaginara = ";
        cin>>imaginar;
        NumarComplex z(real, imaginar);
        v.push_back(z);
    }
}

void afisare(vector<NumarComplex> &v) {
    if (v.empty()) {
        cout<<"Nu exista entitati!"<<'\n';
        return;
    }
    for (int i=0; i<v.size(); i++) {
        cout<<v[i].toString()<<'\n';
    }
}

NumarComplex entitateMaxima(vector<NumarComplex> &v) {
    NumarComplex maxv(0,0);
    for (int i=0; i<v.size(); i++) {
        if (v[i].absolute() > maxv.absolute())
            maxv = v[i];
    }
    return maxv;
}

void entitatiCadran1(vector<NumarComplex> &v, vector<NumarComplex> &rez) {
    rez.clear();
    for (int i = 0; i < v.size(); i++)
        if (v[i].getReal() > 0 && v[i].getImaginar() > 0)
            rez.push_back(v[i]);
}

void secventaEgale(vector<NumarComplex> &v, vector<NumarComplex> &rez) {
    rez.clear();
    int lc, lmax, poz;
    lc = lmax = 0;
    poz = -1;
    for (int i = 1; i < v.size(); i++) {
        if (v[i] == v[i-1])
            lc++;
        else {
            if (lc > lmax) {
                lmax = lc;
                poz = i - lc;
            }
            lc = 1;
        }
    }
    if (lc > lmax) {
        lmax = lc;
        poz = v.size() - lc;
    }
    for (int i = 0; i < lmax; i++)
        rez.push_back(v[poz + i]);
}

void meniu() {
    cout<<'\n';
    cout<<"====MENIU===="<<'\n';
    cout<<"1.Citeste entitati"<<'\n';
    cout<<"2.Afiseaza entitati"<<'\n';
    cout<<"3.Afisaeaza entitatea cea mai mare"<<'\n';
    cout<<"4.Afiseaza entitatile din cadranul 1"<<'\n';
    cout<<"5.Afiseaza secventa maxima de elemente egale"<<'\n';
    cout<<"6.Iesire aplicatie"<<'\n';
}
