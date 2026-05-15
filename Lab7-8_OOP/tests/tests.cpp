#include "tests.h"
#include "../domain/Cheltuiala.h"
#include <cassert>
#include <cstring>
#include <iostream>
#include "../service/Service.h"
#include "../repository/RepoCheltuieli.h"

void testCheltuiala() {
    Cheltuiala c1;
    assert(c1.getNrAp() == 0);
    assert(c1.getSuma() == 0);
    assert(c1.getTip() == nullptr);
    Cheltuiala c2(2,100,"apa");
    assert(c2.getNrAp() == 2);
    assert(c2.getSuma() == 100);
    assert(strcmp(c2.getTip(),"apa")==0);
    c2.setNrAp(5);
    assert(c2.getNrAp() == 5);
    c2.setSuma(200);
    assert(c2.getSuma() == 200);
    c2.setTip("gaz");
    assert(strcmp(c2.getTip(),"gaz") == 0);
}

void testRepo() {
    Cheltuiala c1(1, 100, "apa");
    RepoCheltuieli repo;
    assert(repo.getSize() == 0);
    repo.addElem(c1);
    assert(repo.getSize() == 1);
    Cheltuiala c2(2, 200, "gaz");
    repo.addElem(c2);
    assert(repo.getSize() == 2);
    assert(repo.findOne(c1));
    assert(repo.findOne(c2));
    Cheltuiala* cheltuieli = repo.getAll();
    assert(cheltuieli[0] == c1);
    assert(cheltuieli[1] == c2);
    assert(repo.remove(c1));
    assert(repo.getSize() == 1);
    assert(!repo.findOne(c1));
    assert(repo.update(c2, c1));
    assert(cheltuieli[0] == c1);
    assert(repo.findOne(c1));
}

void testService() {
    RepoCheltuieli* repo = new RepoCheltuieli();
    Service* srv = new Service(repo);
    int nrAp1 = 2;
    int suma1 = 100;
    char * tip1 = nullptr;
    strcpy(tip1,"apa");
    int nrAp2 = 5;
    int suma2 = 200;
    char * tip2 = nullptr;
    strcpy(tip2,"gaz");
    srv->add(nrAp1, suma1, tip1);
    assert(srv->size() == 1);
    assert(srv->find(nrAp1, suma1, tip1));
    srv->add(nrAp2, suma2, tip2);
    assert(srv->size() == 2);
    assert(srv->find(nrAp2, suma2, tip2));
    assert(srv->remove(nrAp1));
    assert(!srv->find(nrAp1, suma1, tip1));
    assert(srv->size() == 1);
    assert(srv->update(nrAp2, suma2, tip2, nrAp1, suma1, tip1));
    assert(srv->find(nrAp1, suma1, tip1));
    assert(!srv->find(nrAp2, suma2, tip2));
    delete srv;
    delete repo;
}

void allTests() {
    testCheltuiala();
    testRepo();
    std::cout<<"All tests passed"<<std::endl;
}
