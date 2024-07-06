#include <iostream>
#include "teste.h"
#include "Errors.h"



void clearFileContent(const std::string& filename) {
    FILE* file = fopen(filename.c_str(), "w");
    if (file != nullptr) {
        fclose(file);
    }
}

void test_domain()
{
    Parcare p{1, "ceva", 2, 2, "XX--"};

    assert(p.get_id() == 1);
    assert(p.getAdresa() == "ceva");
    assert(p.getLinii() == 2);
    assert(p.getColoane() == 2);
    assert(p.getStare() == "XX--");
    assert(p.get_nr_locuri() == 4);

}

void test_repo_store()
{
    clearFileContent("../teste.txt");
    Repo r{"../teste.txt"};
    Parcare p{1, "ceva", 2, 2, "XX--"};

    r.store(p);
    cout << r.get_all().size() << endl;
    assert(r.get_all().size() == 1);
    assert(r.get_all()[0].get_id() == 1);
    assert(r.get_all()[0].getAdresa() == "ceva");
    assert(r.get_all()[0].getLinii() == 2);
    assert(r.get_all()[0].getColoane() == 2);
    assert(r.get_all()[0].getStare() == "XX--");
    assert(r.get_all()[0].get_nr_locuri() == 4);
    clearFileContent("../teste.txt");
}

void test_repo_modify()
{
    clearFileContent("../teste.txt");
    Repo r{"../teste.txt"};
    Parcare p{1, "ceva", 2, 2, "XX--"};
    r.store(p);
    Parcare p1{1, "altceva", 3, 3, "XX--XXXXX"};
    r.modify(p1);
    assert(r.get_all().size() == 1);
    assert(r.get_all()[0].get_id() == 1);
    assert(r.get_all()[0].getAdresa() == "altceva");
    assert(r.get_all()[0].getLinii() == 3);
    assert(r.get_all()[0].getColoane() == 3);
    assert(r.get_all()[0].getStare() == "XX--XXXXX");
    assert(r.get_all()[0].get_nr_locuri() == 9);
    clearFileContent("../teste.txt");
}

void test_service_adaugare(){

    clearFileContent("../teste.txt");
    Repo r{"../teste.txt"};
    Validator v;
    Service s{r, v};
    s.adaugare(1, "ceva", 2, 2, "XX--");
    clearFileContent("../teste.txt");
    assert(r.get_all().size() == 1);
    assert(r.get_all()[0].get_id() == 1);
    assert(r.get_all()[0].getAdresa() == "ceva");

}

void test_service_sortare()
{
    clearFileContent("../teste.txt");
    Repo r{"../teste.txt"};
    Validator v;
    Service s{r, v};
    s.adaugare(1, "ceva", 2, 2, "XX--");
    s.adaugare(2, "altceva", 3, 3, "XX--XXXXX");
    s.adaugare(3, "altceva", 1, 1, "X");
    vector<Parcare> all = s.sortare();
    assert(all.size() == 3);
    assert(all[0].get_id() == 3);
    assert(all[1].get_id() == 1);
    assert(all[2].get_id() == 2);
    clearFileContent("../teste.txt");
}

void test_service_modificare()
{
    clearFileContent("../teste.txt");
    Repo r{"../teste.txt"};
    Validator v;
    Service s{r, v};
    s.adaugare(1, "ceva", 2, 2, "XX--");
    assert(r.get_all().size() == 1);
    assert(r.get_all()[0].get_id() == 1);
    assert(r.get_all()[0].getAdresa() == "ceva");

    try{
    s.modificare(1, "altceva", 1, 1, "X");}
    catch(Exception& e){
        cout<<e.get_msg();
    }
    assert(r.get_all().size() == 1);
    assert(r.get_all()[0].get_id() == 1);
    assert(r.get_all()[0].getAdresa() == "altceva");
    clearFileContent("../teste.txt");



}





void test_all()
{
    test_domain();
    test_repo_store();
    test_repo_modify();
    test_service_adaugare();
    test_service_sortare();
    test_service_modificare();
    cout << "All tests passed!\n";
}