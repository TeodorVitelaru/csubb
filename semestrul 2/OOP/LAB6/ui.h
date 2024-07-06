#include "service.h"
#include "utils.h"
#include "errors.h"

class Consola
{
private:
    Service& srv;
public:
    Consola(Service& srv) :srv{ srv } {};
    Consola(const Consola& ot) = delete;
    void print_menu();
    void adaugare_ui();
    void modificare_ui();
    void stergere_ui();
    void cautare_ui();
    void sortare_ui();
    void filtrare_ui();
    void print_all_oferte(vector<Oferta> allOferte);
    void run();
    void add_default_oferte();
};