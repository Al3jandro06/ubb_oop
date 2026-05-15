#include <iostream>
#include "NumarComplex.h"
#include "operations.h"
#include "tests.h"
using namespace std;

int main() {
    int n = 0, l = 0;
    NumarComplex *v = NULL, *rez = NULL;

    allTests();

    int optiune;
    do {
        meniu();
        cout<<"Alegeti optiunea: ";
        cin>>optiune;
        cout<<'\n';
        switch (optiune) {
            case 1:
                if (v != NULL)
                    delete[] v;
                citire(n,v);
                break;
            case 2:
                afisare(n,v);
                break;
            case 3:
                if (n==0)
                    cout<<"Nu exista un astfel de element"<<'\n';
                else {
                    NumarComplex sol = entitateMaxima(n, v);
                    cout<<sol.toString()<<'\n';
                }
                break;
            case 4:
                entitatiCadran1(n, v, l, rez);
                if (l==0)
                    cout<<"Nu exista astfel de elemente"<<'\n';
                else
                    afisare(l, rez);
                break;
            case 5:
                secventaEgale(n, v, l, rez);
                if (l==0)
                    cout<<"Nu exista o astfel de secventa"<<'\n';
                else
                    afisare(l, rez);
                 break;
            case 6:
                cout<<"La revedere!"<<'\n';
                break;
            default:
                cout<<"Optiunea aleasa nu este implementata! :("<<'\n';
        }
    }while (optiune!=6);

    delete[] v;
    delete[] rez;

    return 0;
}