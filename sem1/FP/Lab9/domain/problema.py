from datetime import datetime


class Problema:
    def __init__(self, nr_prob, descriere, deadline):
        self.__nr_prob = nr_prob
        self.__descriere = descriere
        self.__deadline = deadline

    def get_numar_problema(self):
        return self.__nr_prob

    def get_descriere(self):
        return str(self.__descriere)

    def get_deadline(self):
        return self.__deadline

    def set_descriere(self, descriere_nou):
        self.__descriere = descriere_nou

    def set_deadline(self, deadline_nou):
        self.__deadline = deadline_nou

    def __str__(self):
        return "Nr_prob:" + str(self.__nr_prob) + "/" + "Descriere:" + str(self.__descriere) + "/" + "Deadline"  + str(self.__deadline)

    def __eq__(self, other):
        if self.__nr_prob == other.__nr_prob and self.__descriere == other.__descriere and self.__deadline == other.__deadline:
            return True
        return False