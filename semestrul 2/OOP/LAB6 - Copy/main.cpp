//#include "ui.h"
#include "teste.h"
using namespace std;


void start_app()
{
    Repo repo;
    Validator val;
    Service srv{ repo, val};
    Consola ui{srv};
    ui.run();
}

int main()
{
    test_all();
    start_app();
}