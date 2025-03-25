from domain.problema import Problema
import random
from datetime import datetime
class ProblemaInMemoryRepository:
    def __init__(self):
        self.__lista_probleme = []

    def store(self, problema:Problema):
        """
        Adauga problema in lista de probleme
        :param problema:
        :return:
        """
        if self.find(problema.get_numar_problema()) is not None:
            raise ValueError("Exista deja problema cu acest numar!")
        self.__lista_probleme.append(problema)

    def delete(self, nr_problema):
        problem_to_delete = self.find(nr_problema)
        if problem_to_delete is None:
            raise ValueError("Nu exista problema cu aceste numar!")
        lista_noua = []
        for problema in self.__lista_probleme:
            if problema.get_numar_problema() != nr_problema:
                lista_noua.append(problema)
        self.set_lista_probleme(lista_noua)
        return problem_to_delete

    def modify(self, nr_prob, problema_noua):
        problem_to_modify = self.find(nr_prob)
        if problem_to_modify is None:
            raise ValueError("Nu exista problema cu aceste numere!")
        lista_noua = []
        for problema in self.__lista_probleme:
            if problema.get_numar_problema() != nr_prob:
                lista_noua.append(problema)
            else:
                lista_noua.append(problema_noua)
        self.set_lista_probleme(lista_noua)
        return problem_to_modify

    def find(self, nr_prob):
        for problema in self.__lista_probleme:
            if problema.get_numar_problema() == nr_prob:
                return problema
        return None

    def get_all(self) -> list:
        """
        Retunreaza intreaga lista de probleme
        :return:
        """
        return self.__lista_probleme

    def set_lista_probleme(self, lista_noua):
        """
        Seteaza lista actuala de probleme la o noua lista de probleme
        :param lista_noua: lista cu care trebuie inlocuita cea acutala
        :return: -; lista actuala devine noua lista
        """
        self.__lista_probleme = lista_noua

    def size(self):
        return len(self.__lista_probleme)

    def convert_to_date(self, deadline_str):
        return datetime.strptime(deadline_str, '%Y/%m/%d').date()

    def random_problems(self):
        """
        Generare random de studenti
        :return:
        """
        lista_descriere = ['eu sunt', "tu nu", 'perfect', 'inca incerc', 'o sa fie bine']
        lista_deadline = [self.convert_to_date("2021/01/01"), self.convert_to_date("2021/01/01"), self.convert_to_date("2021/01/02"), self.convert_to_date("2021/01/03"), self.convert_to_date("2021/01/04"),]
        nr_prob = random.randint(1, 10)
        descriere = random.choice(lista_descriere)
        deadline = random.choice(lista_deadline)
        problema  = Problema(nr_prob, descriere, deadline)
        return problema



class ProblemaFileRepository:
    """
    Repo care gestioneaza date din fisier
    """
    def __init__(self, filename):
        self.__filename= filename

    def convert_to_date(self, deadline_str):
        return datetime.strptime(deadline_str, '%Y/%m/%d').date()

    def read_from_file(self):
        with open(self.__filename, mode="r") as f:
            problems = []
            lines = f.readlines()
            for line in lines:
                elements = line.split(',')
                elements = [element.strip() for element in elements]
                nr_prob = int (elements[0])
                descriere = elements[1]
                deadline = self.convert_to_date(elements[2])
                problema = Problema(nr_prob, descriere, deadline)
                problems.append(problema)
            return problems

    def write_to_file(self, lista_probleme):
        with open(self.__filename, mode="w") as f:
            for problema in lista_probleme:
                problema_elements = [problema.get_numar_problema(), problema.get_descriere(), problema.get_deadline()]
                problema_elements = [str(element) for element in problema_elements]
                deadline_elements = problema_elements[2]
                problema_elements.pop()
                deadline_elements = deadline_elements.split("-")
                deadline = '/'.join(deadline_elements)
                problema_elements.append(deadline)
                line = ', '.join(problema_elements) + '\n'
                f.write(line)

    def store(self, problema):
        if self.find(problema.get_numar_problema) is not None:
            raise ValueError("Exista deja problema cu acest numar!")
        lista_probleme = self.read_from_file()
        lista_probleme.append(problema)
        self.write_to_file(lista_probleme)


    def find(self, nr_prob):
        lista_probleme = self.read_from_file()
        for problema in lista_probleme:
            if problema.get_numar_problema() == nr_prob:
                return problema
        return None

    def delete(self, nr_prob):
        lista_probleme = self.read_from_file()
        problema_to_delete = self.find(nr_prob)
        if problema_to_delete is None:
            raise ValueError("Nu exista student cu acest id!")
        lista_probleme.remove(problema_to_delete)
        self.write_to_file(lista_probleme)
        return problema_to_delete

    def modify(self, nr_prob, problema_nou):
        problema_to_modify = self.find(nr_prob)
        if problema_to_modify is None:
            raise ValueError("Nu exista student cu acest id!")
        lista_noua = []
        lista_probleme = self.read_from_file()
        for problema in lista_probleme:
            if problema.get_numar_problema() == nr_prob:
                lista_noua.append(problema_nou)
            else:
                lista_noua.append(problema)
        self.write_to_file(lista_noua)
        return problema_to_modify

    def get_all(self):
        return self.read_from_file()

    def size(self):
        return len(self.read_from_file())

    def convert_to_date(self, deadline_str):
        return datetime.strptime(deadline_str, '%Y/%m/%d').date()

    def random_problems(self):
        """
        Generare random de studenti
        :return:
        """
        lista_descriere = ['eu sunt', "tu nu", 'perfect', 'inca incerc', 'o sa fie bine']
        lista_deadline = [self.convert_to_date("2021/01/01"), self.convert_to_date("2021/01/01"), self.convert_to_date("2021/01/02"), self.convert_to_date("2021/01/03"), self.convert_to_date("2021/01/04"),]
        nr_prob = random.randint(1, 10)
        descriere = random.choice(lista_descriere)
        deadline = random.choice(lista_deadline)
        problema  = Problema(nr_prob, descriere, deadline)
        return problema

    def size(self):
        return len(self.read_from_file())


