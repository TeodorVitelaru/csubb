from domain.melodie import Melodie
from domain.validare import MelodieValidator
from repo.melodie_repo import MelodieFileRepository


class MelodieController:
    def __init__(self, melodie_repo:MelodieFileRepository, melodie_validator:MelodieValidator):
        self.__melodie_repo = melodie_repo
        self.__melodie_validator = melodie_validator

    def modificare_melodie(self, titlu, artist, gen, data):
        """
        Modifica o melodie data
        :param titlu: titlul melodiei
        :param artist: artistul
        :param gen: genul
        :param data: data
        :return:
        """

        melodie = Melodie(titlu, artist, gen, data)
        self.__melodie_validator.validare_melodie(melodie)
        self.__melodie_repo.modify(melodie)

    def adaugare_melodie(self, titlu, artist, gen, data):
        """
        Adaugare melodie in lista
        :param titlu: titlul melodiei
        :param artist: artistul
        :param gen: genul melodiei
        :param data: data de lansare
        :return:
        """

        melodie = Melodie(titlu, artist, gen, data)
        self.__melodie_repo.store(melodie)

    def generare_melodii(self, artisti, titluri):
        """
        Generare melodie
        :param artisti: lista de artisti
        :param titluri: titluri de melodie
        :return: melodia creata random
        """
        return self.__melodie_repo.generate(artisti, titluri)

    def exporta_melodii(self, nume_fisier):
        """
        Exporta intr-un fisier o lista
        :param nume_fisier: numele fisierului in case se exporta
        :return:
        """
        lista_melodii = self.__melodie_repo.get_all()
        #lista_sortata = self.__melodie_repo.merge_sort(lista_melodii, 0, len(lista_melodii))
        self.__melodie_repo.export(nume_fisier, lista_melodii)


    def get_all_melodii(self):
        """
        Returneaza lista de melodii
        :return:
        """
        return self.__melodie_repo.get_all()
