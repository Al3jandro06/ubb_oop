#ifndef LAB7_8_OOP_CHELTUIALA_H
#define LAB7_8_OOP_CHELTUIALA_H


class Cheltuiala {
private:
    int nrAp;
    int suma;
    char* tip;
public:
    Cheltuiala();
    Cheltuiala(int nr, int s, char* t);
    Cheltuiala(const Cheltuiala& c);
    Cheltuiala& operator=(const Cheltuiala& c);

    int getNrAp();
    void setNrAp(int nr);
    int getSuma();
    void setSuma(int s);
    char* getTip();
    void setTip(char* t);

    char* toString();
    bool operator==(const Cheltuiala& c);

    ~Cheltuiala();
};


#endif //LAB7_8_OOP_CHELTUIALA_H