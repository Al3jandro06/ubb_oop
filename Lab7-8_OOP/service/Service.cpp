#include "Service.h"

#include <cstring>

void Service::saveState() {
    vector<Cheltuiala> currentState;
    for (int i = 0; i < this->repo->getSize(); i++) {
        currentState.push_back(this->repo->getAt(i));
    }
    undoStack.push(currentState);
}

Service::Service() {
    this->repo = nullptr;
}

Service::Service(RepoCheltuieli *r) {
    this->repo = r;
}

Service::~Service() {
}

void Service::add(int nrAp, int suma, char* tip) {
    saveState();
    Cheltuiala c(nrAp, suma, tip);
    this->repo->addElem(c);
}

bool Service::find(int nrAp, int suma, char *tip) {
    Cheltuiala c(nrAp, suma, tip);
    return this->repo->findOne(c);
}

bool Service::remove(int nrAp) {
    saveState();
    for (int i = 0; i < this->repo->getSize(); i++) {
        if (this->repo->getAt(i).getNrAp() == nrAp) {
            Cheltuiala c = this->repo->getAt(i);
            if (!this->repo->remove(c))
                return false;
            i--;
        }
    }
    return true;
}

bool Service::update(int nrAp1, int suma1, char *tip1, int nrAp2, int suma2, char *tip2) {
    saveState();
    Cheltuiala c1(nrAp1, suma1, tip1), c2(nrAp2, suma2, tip2);
    return this->repo->update(c1, c2);
}

char ** Service::getAll() {
    char** rez = new char*[this->repo->getSize()];
    Cheltuiala* c = this->repo->getAll();
    for (int i = 0; i < this->repo->getSize(); i++) {
        rez[i] = c[i].toString();
    }
    return rez;
}

int Service::sumTip(char *tip) {
    int suma = 0;
    Cheltuiala* c = this->repo->getAll();
    for (int i = 0; i < this->repo->getSize(); i++) {
        if (strcmp(c[i].getTip(), tip) == 0)
            suma += c[i].getSuma();
    }
    return suma;
}

char ** Service::filter(char *tip, int &l) {
    l = 0;
    char** rez = new char*[this->repo->getSize()];
    Cheltuiala* c = this->repo->getAll();
    for (int i = 0; i < this->repo->getSize(); i++) {
        if (strcmp(c[i].getTip(), tip) == 0)
            rez[l++] = c[i].toString();
    }
    return rez;
}

int Service::size() {
    return this->repo->getSize();
}

bool Service::undo() {
    if (undoStack.empty())
        return false;

    vector<Cheltuiala> previousState = undoStack.top();
    undoStack.pop();

    while (this->repo->getSize() > 0) {
        Cheltuiala c = this->repo->getAt(0);
        this->repo->remove(c);
    }

    for (Cheltuiala& c : previousState) {
        this->repo->addElem(c);
    }

    return true;
}
