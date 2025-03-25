from datetime import datetime

from domain.problema import Problema
from domain.validare import ProblemaValidator
from repository.memory_repository_problema import ProblemaInMemoryRepository


class ProblemaController:
    def __init__(self, repository:ProblemaInMemoryRepository, problema_validator: ProblemaValidator):
        self.__problema_validator = problema_validator
        self.__problema_repo = repository

    def adauga_problema(self, nr_problema, descriere, deadline:datetime):
        """
        Adauga o problema in lista de probleme
        :param nr_lab:
        :param nr_problema:
        :param descriere:
        :param deadline:
        :return:
        :raises:
        """
        problema = Problema(nr_problema, descriere, deadline)
        self.__problema_validator.validare_problema(problema)
        self.__problema_repo.store(problema)

    def modificare_problema(self, nr_prob:int, problema_noua:Problema):
        """
        Modifica problema care are nr_lab si nr_prob
        :param nr_lab:
        :param nr_prob:
        :param problema_noua:
        :return: problema ce trebuie modificata
        :raises: ValueError daca nu exista problema cu nr_lab si nr_prob
        """
        return self.__problema_repo.modify(nr_prob, problema_noua)

    def sterge_problema(self, nr_prob:int):
        """
        Sterge problema dupa nr_lab si nr_prob
        :param nr_lab:
        :param nr_prob:
        :return:
        :raises: ValueError daca nu exista problema cu nr_lab si nr_prob
        """
        return self.__problema_repo.delete(nr_prob)

    def filtrare_dupa_deadline(self, deadline:datetime):
        """
        Filtreaza problemele in functie de deadline
        :param deadline: deadline-ul maxim pt probleme
        :return: lista filtrata
        """
        lista_filtrata = []
        for problema in self.__problema_repo.get_all():
            if problema.get_deadline() < deadline:
                lista_filtrata.append(problema)
        return lista_filtrata

    def generare_random(self):
        problema = self.__problema_repo.random_problems()
        self.__problema_repo.store(problema)

    def get_all_problems(self) -> list:
        """
        Returneaza lista cu toate problemele
        :return:
        """
        return self.__problema_repo.get_all()