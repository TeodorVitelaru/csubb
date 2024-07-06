//#define _CRTDBG_MAP_ALLOC
//#include <crtdbg.h>
//#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "domain.h"
#include "controller.h"
#include "repository.h"
#include "validator.h"
#include "UI.h"
void test_modules()
{
    test_validation();

    Repository repo = create_Repo(100);
    detroy_Repo(repo);
    test_domain();


    repo = create_Repo(100);
    Controller controller = create_Controller(repo);
    test_controller(controller);
    destroy_Controller(controller);
}

int main()
{

    test_modules();

    Repository repo = create_Repo(100);
    Controller controller = create_Controller(repo);
    add_Oferta_Repo(controller->repo, create_Oferta("teren", 52, "Sibiu,str.Luncii,nr.14", 350));
    add_Oferta_Repo(controller->repo, create_Oferta("casa", 120, "Cluj,str.Aurel Vlaicu,nr.184", 250));
    add_Oferta_Repo(controller->repo, create_Oferta("apartament", 25, "Cluj,str.Libertatii,nr.1", 550));
    add_Oferta_Repo(controller->repo, create_Oferta("teren", 375, "Sibiu,str.Rovine,nr.12", 5550));
    add_Oferta_Repo(controller->repo, create_Oferta("casa", 275, "Pitesti,str.Ploiesti,nr.23", 150));
    add_Oferta_Repo(controller->repo, create_Oferta("casa", 175, "Alba-Iulia,str.Neagra,nr.5", 1550));

    run_console(controller);
    destroy_Controller(controller);
    //_CrtDumpMemoryLeaks();
    return 0;
}