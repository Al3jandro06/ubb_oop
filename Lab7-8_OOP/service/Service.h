#ifndef LAB7_8_OOP_SERVICE_H
#define LAB7_8_OOP_SERVICE_H
#include "../repository/RepoCheltuieli.h"
#include <stack>
#include <vector>
using namespace std;

class Service {
private:
    RepoCheltuieli* repo;
    stack<vector<Cheltuiala>> undoStack;

    void saveState();
public:
    Service();
    Service(RepoCheltuieli* r);
    ~Service();
    void add(int nrAp, int suma, char* tip);
    bool find(int nrAp, int suma, char* tip);
    bool remove(int nrAp);
    bool update(int nrAp1, int suma1, char* tip1, int nrAp2, int suma2, char* tip2);
    char** getAll();
    int sumTip(char* tip);
    char** filter(char* tip, int &l);
    int size();
    bool undo();
};


#endif //LAB7_8_OOP_SERVICE_H