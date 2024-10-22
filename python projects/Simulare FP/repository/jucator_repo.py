from domain.jucator import Jucator


class JucatorFileRepository:

    def __init__(self, filename):
        self.__filename = filename

    def read_from_file(self):
        """
        Citirea datelor din fisier
        :return: lista de obiecte de tip jucator
        """
        with open(self.__filename, mode="r") as f:
            lista_jucatori = []
            lines = f.readlines()
            for line in lines:
                elements = line.split(",")
                elements = [element.strip() for element in elements]
                id = elements[0]
                nume = elements[1]
                pozitie = elements[2]
                puncte = int(elements[3])
                jucator = Jucator(id, nume, pozitie, puncte)
                lista_jucatori.append(jucator)
            return lista_jucatori

    def find(self, id):
        """
        Cautarea jucatorul dupa id
        :param id: id-ul jucatorului
        :param type: str
        :return: jucator gasit sau None in caz contrar
        """
        lista_jucatori = self.read_from_file()
        for jucator in lista_jucatori:
            if jucator.get_id() == id:
                return jucator
        return None

    def get_all(self):
        """
        Se returneaza lista de jucatori
        :return type: lista de obiecte
        """
        return self.read_from_file()