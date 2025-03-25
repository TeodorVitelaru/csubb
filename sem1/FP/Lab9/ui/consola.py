from datetime import datetime

from colorama import Fore, Style

from domain.problema import Problema
from domain.student import Student
from service.serivice_student import StudentController
from service.service_nota import NotaController
from service.service_problema import ProblemaController

studentID = 0

class Consola:
    def __init__(self, student_controller:StudentController, problema_controller: ProblemaController, nota_controller:NotaController):
        self.__student_service = student_controller
        self.__problema_service = problema_controller
        self.__nota_service = nota_controller

    def __print_menu(self):
        print("MENIU\n"
              "             GENERARE RANDOM\n"
              "     1r.generare de n studenti\n"
              "     2r.generare de n probleme\n"
              "             STUDENT\n"
              "     1s. adaugare\n"
              "     2s. stergere\n"
              "     3s. modificare\n"
              "     4s. filtrare dupa grupa\n"
              "             PROBLEMA\n"
              "     1p. adaugare\n"
              "     2p. stergere\n"
              "     3p. modificare\n"
              "     4p. filtrare dupa deadline\n"
              "      p. printare\n"
              "            ATRIBUIRI\n"
              "     1a. atribuiri probleme si nota\n"
              "     a. afisare lista de notari\n"
              "            STATISTICI\n"
              "     1b.ordonat alfabetic pentru o problema\n"
              "     2b.ordonat crescator dupa nota\n"
              "     3b. studentii cu media mai mica decat 5\n"
              "4.iesire")

    def convert_to_date(self, deadline_str):
        return datetime.strptime(deadline_str, '%Y/%m/%d').date()





    #STUDENT
    def print_lista_de_studenti(self, lista_de_studenti):
        if len(lista_de_studenti) > 0:
            print(Fore.LIGHTYELLOW_EX + "Lista de studenti este:")
            for student in lista_de_studenti:
                print(student)
            print("\n" + Style.RESET_ALL)
        else:
            print(Fore.LIGHTYELLOW_EX + "Lista de studenti este goala\n" + Style.RESET_ALL)


    def adauga_student_ui(self):
        studentID = input("Introduceti id-ul: ")
        nume = input("Introduceti numele: ")
        grupa = (input("Introduceti numarul grupei: "))
        try:
            grupa = int(grupa)
            studentID = int(studentID)
            self.__student_service.adauga_student(studentID, nume, grupa)
            print(Fore.LIGHTCYAN_EX + "SUCCES: Adaugarea s a realizat cu succes!" + Style.RESET_ALL)
        except ValueError as e:
            print(Fore.RED + "EROARE:" + str(e) + Style.RESET_ALL)



    def stergere_student_ui(self):
        studentID = input("Introduceti id ul studentului ce vreti sa fie sters: ")
        try:
            studentID = int(studentID)
            student_sters = self.__student_service.stergere_student(studentID)
            print(Fore.LIGHTCYAN_EX + "SUCCES: Stergerea s a realizat cu succes!" + Style.RESET_ALL)
            print('Studentul', str(student_sters), 's-a sters cu succes.')
        except ValueError as e:
            print(Fore.RED + str(e) + Style.RESET_ALL)


    def modificare_student_ui(self):
        self.print_lista_de_studenti(self.__student_service.get_all_students())
        studentID_modify = input("Introduceti id-ul: ")
        try:
            studentID_modify = int(studentID_modify)
            studentID = int(input("Introduceti noul id-ul: "))
            nume = input("Introduceti noul nume: ")
            grupa = int(input("Introduceti noua grupa: "))
            student_nou = Student(studentID, nume, grupa)
            student_modificat = self.__student_service.modificare_student(studentID_modify, student_nou)
            print(Fore.LIGHTCYAN_EX + "SUCCES: Elev modificat!" + Style.RESET_ALL )
            print('Studentul', str(student_modificat), 's-a modificat cu succes.')
        except ValueError as e:
                print(Fore.RED + str(e) + Style.RESET_ALL)


    def filtrare_studenti_ui(self):
        grupa = input("Introduceti grupa: ")
        try:
            grupa = int(grupa)
            lista_filtrata = self.__student_service.filtrare_dupa_grupa(grupa)
            if len(lista_filtrata) > 0:
                print(Fore.WHITE + "Studentii din grupa " + str(grupa)+ " sunt:")
                self.print_lista_de_studenti(lista_filtrata)
                print(Style.RESET_ALL)
            else:
                print(Fore.RED + "Nu exista studenti din grupa aleasa!" + Style.RESET_ALL)
        except ValueError:
            print("Grupa introdusa nu este un numar!")





    #PROBLEMA
    def print_lista_de_probleme(self, lista_de_probleme):
        if len(lista_de_probleme) > 0:
            print(Fore.LIGHTYELLOW_EX + "Lista de probleme este:")
            for student in lista_de_probleme:
                print(student)
            print("\n" + Style.RESET_ALL)
        else:
            print(Fore.LIGHTYELLOW_EX + "Lista de probleme este goala\n" + Style.RESET_ALL)


    def adauga_problema_ui(self):
        nr_problema = input("Introduceti numarul problemei: ")
        descriere = input("Introduceti descrierea: ")
        deadline_str = input("Introduceti data yy/mm/dd: ")
        try:
            deadline = self.convert_to_date(deadline_str)
            nr_problema = int(nr_problema)
            self.__problema_service.adauga_problema(nr_problema, descriere, deadline)
            print(Fore.LIGHTCYAN_EX + "SUCCES: Adaugarea s a realizat cu succes!" + Style.RESET_ALL)
        except ValueError as e:
            print(Fore.RED + str(e) + Style.RESET_ALL)


    def stergere_problema_ui(self):
        self.print_lista_de_probleme(self.__problema_service.get_all_problems())
        nr_prob = input("Introduceti numarul problemei: ")
        try:
            nr_prob = int(nr_prob)
            problema_de_sters = self.__problema_service.sterge_problema(nr_prob)
            print(Fore.LIGHTCYAN_EX + "SUCCES: Stergerea s a realizat cu succes!" + Style.RESET_ALL)
            print('Problema', str(problema_de_sters), 's-a sters cu succes.')
        except ValueError as er:
            print(Fore.RED + str(er) + Style.RESET_ALL + "\n")


    def filtrare_probleme_ui(self):
        deadline_str = input("Introduceti deadline-ul YY/mm/dd:")
        try:
            deadline = self.convert_to_date(deadline_str)
            lista_filtrata = self.__problema_service.filtrare_dupa_deadline(deadline)
            if len(lista_filtrata) > 0:
                print(Fore.WHITE + "Problemele pana la deadline-ul " + deadline_str + " sunt:")
                self.print_lista_de_probleme(lista_filtrata)
                print(Style.RESET_ALL)
            else:
                print(Fore.RED + "Nu exista probleme pana la deadline-ul " + deadline_str + Style.RESET_ALL)
        except ValueError:
            print(Fore.RED + "Introduceti valori valide pentru data!" + Style.RESET_ALL)



    def modificare_problema_ui(self):
        self.print_lista_de_probleme(self.__problema_service.get_all_problems())
        nr_prob_to_modify = input("Introduceti numarul problemei: ")
        try:
            nr_prob_to_modify = int(nr_prob_to_modify)
            nr_prob= input("Introduceti numarul problemei: ")
            nr_prob = int(nr_prob)
            descriere = input("Introduceti descrierea: ")
            deadline_str = input("Introduceti deadline: ")
            deadline = self.convert_to_date(deadline_str)
            problema_noua = Problema(nr_prob, descriere, deadline)
            problem_to_modify = self.__problema_service.modificare_problema(nr_prob_to_modify, problema_noua)
            print(Fore.LIGHTCYAN_EX + "SUCCES: Problema modificata!" + Style.RESET_ALL)
            print('Problema', str(problem_to_modify), 's-a modificat cu succes.')
        except ValueError as e:
            print(Fore.RED + str(e) + Style.RESET_ALL)




    #ATRIBUIRI
    def print_lista_atriburi(self, lista_atriburi):
        if len(lista_atriburi) > 0:
            print(Fore.LIGHTYELLOW_EX + "Lista de atribuiri este:")
            for atribuire in lista_atriburi:
                print(atribuire)
            print("\n" + Style.RESET_ALL)
        else:
            print(Fore.LIGHTYELLOW_EX + "Lista de atribuiri este goala\n" + Style.RESET_ALL)

    def adauga_note_ui(self):
        studentID = input("Introduceti id-ul pentru student: ")
        nr_prob = input("Introduceti numarul problemei: ")
        nota = input("Introduceti nota: ")
        try:
            studentID = int(studentID)
            nr_prob = int(nr_prob)
            nota = int(nota)
            self.__nota_service.adaugare_nota(studentID, nr_prob, nota)
            print(Fore.LIGHTCYAN_EX + "SUCCES: Studentul a primit o nota la o problema!" + Style.RESET_ALL)
        except ValueError as e:
            print(Fore.RED + str(e) + Style.RESET_ALL)





    #GENERARI
    def random_student_ui(self):
        numar = int(input("Introduceti un numar: "))
        try:
            for i in range(numar):
                self.__student_service.generare_random()
            print(Fore.LIGHTCYAN_EX + "SUCCES: Studenti adaugati!" + Style.RESET_ALL)
        except ValueError as e:
            print(Fore.RED + str(e) + Style.RESET_ALL)

    def random_problem_ui(self):
        numar = int(input("introduceti un numar: "))
        try:
            for i in range(numar):
                self.__problema_service.generare_random()
            print(Fore.LIGHTCYAN_EX + "SUCCES: Studenti adaugati!" + Style.RESET_ALL)
        except ValueError as e:
            print(Fore.RED + str(e) + Style.RESET_ALL)





    #STATISTICI
    def sortare_dupa_prob_nume_ui(self):
        nr_prob = input("Introduceti un numar de problema: ")
        try:
            nr_prob = int(nr_prob)
            lista_sortata = self.__nota_service.sortare_dupa_prob_nume(nr_prob)
            for pereche in lista_sortata:
                student = pereche[0]
                nota = pereche[1]
                print("Student:" + str(student) + " / " + "Nota: " + str(nota))
        except ValueError as e:
            print(Fore.RED + str(e) + Style.RESET_ALL)

    def sortare_dupa_prob_nota_ui(self):
        nr_prob = input("Introduceti un numar de problema: ")
        try:
            nr_prob = int(nr_prob)
            lista_sortata = self.__nota_service.sortare_dupa_prob_nota(nr_prob)
            for pereche in lista_sortata:
                student = pereche[0]
                nota = pereche[1]
                print("Student:" + str(student) + " / " + "Nota: " + str(nota))
        except ValueError as e:
            print(Fore.RED + str(e) + Style.RESET_ALL)

    def medie_mai_mic_5_ui(self):
        try:
            lista_stud_medie = self.__nota_service.medie_mai_mic_5()
            for pereche in lista_stud_medie:
                student_name = pereche[0]
                media = pereche[1]
                print("Student: " + str(student_name) + " || " + "Media: " + str(media))
        except ValueError as e:
            print(Fore.RED + str(e) + Style.RESET_ALL)

    def studenti_fara_note_ui(self):
        try:
            lista_studenti = self.__nota_service.studenti_fara_note()
            for student in lista_studenti:
                print(student)
        except ValueError as e:
            print(Fore.RED + str(e) + Style.RESET_ALL)



    def run(self):
        while True:
            self.__print_menu()
            option = input("Introduceti optiunea: ")
            if option == 's':
                self.print_lista_de_studenti(self.__student_service.get_all_students())
            elif option == 'p':
                self.print_lista_de_probleme(self.__problema_service.get_all_problems())
            elif option == 'a':
                self.print_lista_atriburi(self.__nota_service.get_all_notes())
            elif option == '1s':
                self.adauga_student_ui()
            elif option == '2s':
                self.stergere_student_ui()
            elif option == '3s':
                self.modificare_student_ui()
            elif option == '4s':
                self.filtrare_studenti_ui()
            elif option == "1p":
                self.adauga_problema_ui()
            elif option == "2p":
                self.stergere_problema_ui()
            elif option == '3p':
                self.modificare_problema_ui()
            elif option == '4p':
                self.filtrare_probleme_ui()
            elif option == '1a':
                self.adauga_note_ui()
            elif option == "1r":
                self.random_student_ui()
            elif option == '2r':
                self.random_problem_ui()
            elif option == '1b':
                self.sortare_dupa_prob_nume_ui()
            elif option == '2b':
                self.sortare_dupa_prob_nota_ui()
            elif option == '3b':
                self.medie_mai_mic_5_ui()
            elif option == '4b':
                self.studenti_fara_note_ui()
            elif option == '4':
                break