#ifndef LAB7_8_OOP_UI_H
#define LAB7_8_OOP_UI_H
#include "../service/Service.h"


class UI {
private:
    Service* srv;
    void adaugare();
    void stergere();
    void listare();
    void sumaTotalaTip();
    void filtrare();
    void undo();
    void meniu();
public:
    UI();
    UI(Service* s);
    void run();
    ~UI();
};


#endif //LAB7_8_OOP_UI_H