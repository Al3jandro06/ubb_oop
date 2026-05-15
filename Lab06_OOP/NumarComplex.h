#ifndef LAB06_OOP_NUMARCOMPLEX_H
#define LAB06_OOP_NUMARCOMPLEX_H


class NumarComplex {
private:
    double real;
    double imaginar;
public:
    NumarComplex();
    NumarComplex(double, double);
    NumarComplex(const NumarComplex&);
    NumarComplex& operator=(const NumarComplex&);
    ~NumarComplex();

    double getReal();
    double getImaginar();
    void setReal(double);
    void setImaginar(double);

    char* toString();

    bool operator==(const NumarComplex&);

    NumarComplex operator+(const NumarComplex&);
    NumarComplex operator-(const NumarComplex&);
    NumarComplex operator*(const NumarComplex&);
    double absolute();
    NumarComplex conjugate();
};


#endif //LAB06_OOP_NUMARCOMPLEX_H