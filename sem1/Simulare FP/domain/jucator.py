
class Jucator:
    def __init__(self, id, nume, pozitie, puncte):
        self.__id = id
        self.__nume = nume
        self.__pozitie = pozitie
        self.__puncte = puncte

    def get_id(self):
        return self.__id

    def get_nume(self):
        return self.__nume

    def get_pozitie(self):
        return self.__pozitie

    def get_puncte(self):
        return self.__puncte

    def __str__(self):
        return "id:" + self.get_id() + " || " + "nume:" + self.get_nume() + " || " + "pozitie:" + self.get_pozitie() + " || " + "puncte:" + str(self.get_puncte())