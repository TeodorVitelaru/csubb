from repository.jucator_repo import JucatorFileRepository


class JucatorController:
    def __init__(self, jucator_repo:JucatorFileRepository):
        self.__jucator_repo = jucator_repo

    def catuare_dupa_pozitie(self, pozitie):
        """
        Cautare jucatorii de pe o pozitie data
        :param pozitie: pozitia care se cauta
        :return: lista de jucatori de pe pozitia data
        """
        lista_jucatori = self.__jucator_repo.get_all()
        lista_jucatori_pozitie = []
        for jucator in lista_jucatori:
            if jucator.get_pozitie() == pozitie:
                lista_jucatori_pozitie.append(jucator)
        return lista_jucatori_pozitie