from service.melodie_service import MelodieController


class Consola:
    """
    Clasa pentru consola
    """
    def __init__(self, melodie_controller:MelodieController):
        self.__melodie_controller = melodie_controller

    def print_menu(self):
        print("MENIU\n"
              "p.Print melodii\n"
              "1.Modificare melodie\n"
              "2.Generare melodie\n"
              "3.Export\n"
              "e.Iesire\n")

    def print_lista(self, lista_melodii):
        for melodie in lista_melodii:
            print(melodie)

    def modificare_melodie_ui(self):
        titlu = input("Introduceti titlu: ")
        artist = input("Introduceti artistul: ")
        gen = input("Introduceti genul: ")
        data = input("Introduceti data: ")
        try:
            self.__melodie_controller.modificare_melodie(titlu, artist, gen, data)
            print("SUCCES!")
        except ValueError as er:
            print("EROARE: " + str(er))

    def generare_melodie_ui(self):
        n = input("Introduceti nr: ")
        lista_artisti =  input("Introduceti lista artisti: ")
        lista_titluri = input("Introduceti lista titluri: ")
        nr_melodii_create = 0
        try:
            n= int(n)
            artisti = lista_artisti.split(",")
            artisti = [element.strip() for element in artisti]
            titluri = lista_titluri.split(',')
            titluri = [element.strip() for element in titluri]
            for i in range(n):
                melodie = self.__melodie_controller.generare_melodii(artisti, titluri)
                try:
                    self.__melodie_controller.adaugare_melodie(melodie.get_titlu(), melodie.get_artist(), melodie.get_gen(), melodie.get_data())
                    nr_melodii_create += 1
                except ValueError:
                    pass
            print("SUCCES: S au generat " + str(nr_melodii_create))
        except ValueError as er:
            print("EROARE: " + str(er))

    def exporta_melodii_ui(self):
        nume_fisier = input("Introduceti numele fisierului: ")
        try:
            self.__melodie_controller.exporta_melodii(nume_fisier)
            print("SUCCES!")
        except ValueError as er:
            print("EROARE: " + str(er))

    def run(self):
        while True:
            self.print_menu()
            option = input("Introduceti optiunea: ")
            if option == 'p':
                self.print_lista(self.__melodie_controller.get_all_melodii())
            elif option == '1':
                self.modificare_melodie_ui()
            elif option == 'e':
                break
            elif option == '2':
                self.generare_melodie_ui()
            elif option == '3':
                self.exporta_melodii_ui()
