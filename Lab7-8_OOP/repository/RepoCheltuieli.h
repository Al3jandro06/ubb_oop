#ifndef LAB7_8_OOP_REPOCHELTUIELI_H
#define LAB7_8_OOP_REPOCHELTUIELI_H

#include "../domain/Cheltuiala.h"

class RepoCheltuieli {
private:
    Cheltuiala* cheltuieli;
    int size;
    int capacity;
    void resize();
    int poz(Cheltuiala& c);
public:
    RepoCheltuieli();
    void addElem(Cheltuiala& c);
    bool update(Cheltuiala& c1, Cheltuiala& c2);
    bool findOne(Cheltuiala& c);
    bool remove(Cheltuiala& c);

    int getSize();
    Cheltuiala getAt(int poz);
    Cheltuiala* getAll();

    ~RepoCheltuieli();
};


#endif //LAB7_8_OOP_REPOCHELTUIELI_H