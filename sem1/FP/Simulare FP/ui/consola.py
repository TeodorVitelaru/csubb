from repository.jucator_repo import JucatorFileRepository
from service.jucator_service import JucatorController
from service.mvp_service import MvpController


class Consola:

    def __init__(self, jucator_service:JucatorController, mvp_service:MvpController):
        self.__jucator_service = jucator_service
        self.__mvp_service = mvp_service

    def print_menu(self):
        print("MENIU\n"
              "1.Cautare dupa pozitie\n"
              "2. Evolutie jucator")

    def cautare_dupa_pozitie_ui(self):
        pozitie = input("Introduceti o pozitie: ")
        lista_jucatori = self.__jucator_service.catuare_dupa_pozitie(pozitie)
        for jucator in lista_jucatori:
            print(jucator)

    def evolutie_ui(self):
        id = input("Introduceti id: ")
        numar_meciuri = int(input("Introduceti un numar de meciuri: "))
        mvp = self.__mvp_service.evolutie(id, numar_meciuri)
        print(mvp)

    def run(self):
        while True:
            self.print_menu()
            option = input("Introduceti optiunea: ")
            if option == '1':
                self.cautare_dupa_pozitie_ui()
            if option == '2':
                self.evolutie_ui()
