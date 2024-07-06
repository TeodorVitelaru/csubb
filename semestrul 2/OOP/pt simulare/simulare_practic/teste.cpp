#include "Service.h"
#include <iostream>
#include "teste.h"
#include <assert.h>
#include "Errors.h"


void test_domain()
{
    Elev ev{2, "ceva", "ceva"};
    assert(ev.get_nrMatricol() == 2);
    assert(ev.get_nume() == "ceva");
    assert(ev.get_scoala() == "ceva");
    ev.set_nrMatricol(3);
    assert(ev.get_nrMatricol() == 3);
    ev.set_nume("altceva");
    assert(ev.get_nume() == "altceva");
}

void test_store()
{
    Repo repo{"../test.txt"};
    Elev ev{2, "ceva", "ceva"};
    ev.set_atelier("ceva");
    repo.store(ev);
    assert(repo.getElevi().size() == 1);
    Elev ev2{3, "altceva", "altceva"};
    repo.store(ev2);
    assert(repo.getElevi().size() == 2);
    repo.del(ev);
    repo.del(ev2);
}

void test_del()
{
    Repo repo{"../test.txt"};
    Elev ev{2, "ceva", "ceva"};
    repo.store(ev);
    assert(repo.getElevi().size() == 1);
    repo.del(ev);
    assert(repo.getElevi().size() == 0);
}

void test_sortare()
{
    Repo repo{"../test.txt"};
    Elev ev{2, "ceva", "ceva"};
    Elev ev2{3, "altceva", "altceva"};
    repo.store(ev);
    repo.store(ev2);
    Service serv{repo};
    serv.sortare_nume();
    assert(serv.getElevi()[0].get_nume() == "altceva");
    assert(serv.getElevi()[1].get_nume() == "ceva");
    repo.del(ev);
    repo.del(ev2);
}

void test_all()
{
    test_domain();
    test_store();
    test_del();
    test_sortare();
    cout<<"All tests passed!\n";
}