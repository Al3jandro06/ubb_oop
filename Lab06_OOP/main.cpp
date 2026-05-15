#include <iostream>
#include <vector>
#include "NumarComplex.h"
#include "tests.h"
#include "operations.h"

using namespace std;

int main() {
    vector<NumarComplex> v, rez;

    allTests();

    int optiune;
    do {
        meniu();
        cout<<"Introduceti optiunea: ";
        cin>>optiune;
        cout<<'\n';
        switch (optiune) {
            case 1:
                if (!v.empty())
                    v.clear();
                citire(v);
                break;
            case 2:
                afisare(v);
                break;
            case 3:
                if (v.empty())
                    cout<<"Nu exista astfel de element!"<<'\n';
                else {
                    NumarComplex z = entitateMaxima(v);
                    cout<<z.toString()<<'\n';
                }
                break;
            case 4:
                entitatiCadran1(v, rez);
                if (rez.empty())
                    cout<<"Nu exista astfel de elemente!"<<'\n';
                else
                    afisare(rez);
                break;
            case 5:
                secventaEgale(v, rez);
                if (rez.empty())
                    cout<<"Nu exista o astfel de secventa!"<<'\n';
                else
                    afisare(rez);
                break;
            case 6:
                cout<<"La revedere!"<<'\n';
                break;
            default:
                cout<<"Optiunea aleasa nu este implementata! :("<<'\n';
        }
    }while(optiune!=6);

    return 0;
}