import random

from domain.melodie import Melodie


class MelodieFileRepository:
    """
    Repo pentru Melodii
    """

    def __init__(self, filename):
        self.__filename = filename

    def read_from_file(self):
        """
        Citeste din fisier melodiile
        :return:
        """
        lista_melodii = []
        with open(self.__filename, mode="r") as f:
            lines = f.readlines()
            for line in lines:
                elements = line.split(',')
                elements = [element.strip() for element in elements]
                titlu = elements[0]
                artist = elements[1]
                gen = elements[2]
                data = elements[3]
                melodie = Melodie(titlu, artist, gen, data)
                lista_melodii.append(melodie)
            return lista_melodii

    def write_to_file(self, lista_melodii):
        """
        Scrie in fisier lista de melodii
        :param lista_melodii: lista de melodii
        :return:
        """
        with open(self.__filename, mode="w") as f:
            for melodie in lista_melodii:
                melodie_elements = [melodie.get_titlu(), melodie.get_artist(), melodie.get_gen(), melodie.get_data()]
                melodie_elements = [str(element) for element in melodie_elements]
                line = ', '.join(melodie_elements) + '\n'
                f.write(line)

    def store(self, melodie):
        """
        Adauga in fisier o melodie noua
        :param melodie: melodie
        :return:
        """
        melodie_existenta = self.find(melodie.get_titlu(), melodie.get_artist())
        if melodie_existenta is not None:
            raise ValueError("Exista deja piesa!")
        lista_noua = self.read_from_file()
        lista_noua.append(melodie)

        self.write_to_file(lista_noua)

    def modify(self, melodie_noua):
        """
        Modifica melodie data si salveaza valorile in fisier
        :param melodie_noua: melodia data
        :return:
        :raises: ValueError daca melodia nu exista
        """
        melodie_to_modify = self.find(melodie_noua.get_titlu(), melodie_noua.get_artist())
        if melodie_to_modify is None:
            raise ValueError("Nu exista melodia!")
        lista_noua = []
        lista_melodie = self.read_from_file()
        for melodie in lista_melodie:
            if melodie == melodie_to_modify:
                lista_noua.append(melodie_noua)
            else:
                lista_noua.append(melodie)
        self.write_to_file(lista_noua)

    def find(self, titlu, artist):
        """
        Cauta o melodie dupa titlu si artist
        :param titlu: titlul
        :param artist: artistul
        :return: melodia gasita
        """
        lista_melodii = self.read_from_file()
        for melodie in lista_melodii:
            if melodie.get_artist() == artist and melodie.get_titlu() == titlu:
                return melodie
        return None

    def generate(self, lista_artisti, lista_titluri):
        genuri = ["Rock", "Jazz", "Pop"]
        gen = random.choice(genuri)
        artist = random.choice(lista_artisti)
        titlu = random.choice(lista_titluri)
        data = "01.01.2020"
        melodie = Melodie(titlu, artist, gen, data)
        return melodie

    def get_all(self):
        """
        Returneaza lista de melodii
        :return:
        """
        return self.read_from_file()

    def export(self, nume_fisier, lista_melodii):
        """
        Exporta melodiile dintr o lista
        :param nume_fisier: numele fisierului in care se exporta
        :param lista_melodii: lista de melodii
        :return:
        """
        with open(nume_fisier, mode="w") as f:
            for melodie in lista_melodii:
                melodie_elements = [melodie.get_titlu(), melodie.get_artist(), melodie.get_gen(), melodie.get_data()]
                melodie_elements = [str(element) for element in melodie_elements]
                line = ', '.join(melodie_elements) + '\n'
                f.write(line)

    def merge_sort(self, l, left, right):
        if left >= right -1:
            return
        m = (left + right) // 2
        self.merge_sort(l, left, m)
        self.merge_sort(l, m, right)
        self.merge(l, left, right, m)

    def merge(self, l, left, right, m):
        n1 = m - left + 1
        n2 = right - m
        L = [0] * n1
        R = [0] * n2
        for i in range(n1):
            L[i] = l[left+i]
        for j in range(n2):
            R[j] = l[m+j]
        i = 0
        j = 0
        k = left
        while i<n1 and j<n2:
            if L[i].get_data()<R[j].get_data():
                l[k] = L[i]
                i += 1
            else:
                l[k] = R[j]
                j += 1
            k += 1
        while i<n1:
            l[k] = L[i]
            k += 1
            i += 1
        while j<n2:
            l[k] = R[j]
            k += 1
            j += 1

    def size(self):
        return len(self.read_from_file())


