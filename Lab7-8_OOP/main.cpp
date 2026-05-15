#include <iostream>
#include "tests/tests.h"
#include "ui/UI.h"

using namespace std;

int main() {
    allTests();

    RepoCheltuieli* repo = new RepoCheltuieli();
    Service* srv = new Service(repo);
    UI* console = new UI(srv);
    console->run();
    delete console;
    delete srv;
    delete repo;

    return 0;
}