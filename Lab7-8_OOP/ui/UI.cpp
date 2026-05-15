#include "UI.h"

#include <cstring>
#include <iostream>
using namespace std;

void UI::adaugare() {
    int nrAp, suma;
    char* tip = new char[20];
    char aux[20];
    cout<<"Apartament: ";
    cin>>nrAp;
    cout<<"Tip: ";
    cin>>aux;
    strcpy(tip, aux);
    cout<<"Suma: ";
    cin>>suma;
    srv->add(nrAp, suma, tip);
    delete[] tip;
}

void UI::stergere() {
    int nrAp;
    cout<<"Apartament: ";
    cin>>nrAp;
    bool rez = srv->remove(nrAp);
    if (rez)
        cout<<"Cheltuielile au fost eliminate cu succes!"<<endl;
    else
        cout<<"Nu s-au putut efectua eliminarile!"<<endl;
}

void UI::listare() {
    int nr = this->srv->size();
    if (nr == 0) {
        cout<<"Nu exista cheltuieli!"<<endl;
        return;
    }

    char ** chelt = this->srv->getAll();
    for (int i = 0; i < this->srv->size(); i++) {
        cout<<"Cheltuiala: "<<chelt[i]<<endl;
        delete chelt[i];
    }
    delete[] chelt;
}

void UI::sumaTotalaTip() {
    char *tip = new char[20];
    char aux[20];
    cout<<"Tip: ";
    cin>>aux;
    strcpy(tip, aux);
    cout<<"Suma totala "<<aux<<": "<<this->srv->sumTip(tip)<<endl;
    delete[] tip;
}

void UI::filtrare() {
    char *tip = new char[20];
    char aux[20];
    cout<<"Tip: ";
    cin>>aux;
    strcpy(tip, aux);
    int l;
    char** rez = this->srv->filter(tip, l);
    if (l == 0) {
        cout<<"Nu exista cheltuielile!"<<endl;
        return;
    }
    for (int i = 0; i < l; i++) {
        cout<<"Cheltuiala: "<<rez[i]<<endl;
        delete rez[i];
    }
    delete[] rez;
}

void UI::undo() {
    bool success = this->srv->undo();
    if (success) {
        cout << "Undo realizat cu succes!" << endl;
    } else {
        cout << "Nu se poate realiza undo!" << endl;
    }
}

void UI::meniu() {
    cout<<"=====Meniu====="<<endl;
    cout<<"1.Adauga cheltuiala"<<endl;
    cout<<"2.Eliminare cheltuieli apartament"<<endl;
    cout<<"3.Listeaza toate cheltuielile"<<endl;
    cout<<"4.Afiseaza suma totala dupa tip"<<endl;
    cout<<"5.Filtrare"<<endl;
    cout<<"6.Undo"<<endl;
    cout<<"0.Exit"<<endl;
}

UI::UI() {
    srv = nullptr;
}

UI::UI(Service *s) {
    srv = s;
}

void UI::run() {
    int optiune;
    do {
        meniu();
        cout<<"Intoduceti optiunea: ";
        cin>>optiune;
        switch (optiune) {
            case 0:
                cout<<"La revedere!"<<endl;
                break;
            case 1:
                adaugare();
                break;
            case 2:
                stergere();
                break;
            case 3:
                listare();
                break;
            case 4:
                sumaTotalaTip();
                break;
            case 5:
                filtrare();
                break;
            case 6:
                undo();
                break;
            default:
                cout<<"Aceasta optiune nu exista!"<<endl;
                break;
        }
    }while (optiune != 0);
}

UI::~UI() {
}
