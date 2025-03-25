from domain.MVPCandidate import MVPCandidate
from repository.jucator_repo import JucatorFileRepository
from repository.mvp_repo import MvpInMemoryRepository


class MvpController:
    def __init__(self, mvp_repo:MvpInMemoryRepository, jucator_repo:JucatorFileRepository):
        self.__mvp_repo = mvp_repo
        self.__jucator_repo = jucator_repo

    def evolutie(self, id, numar_meciuri:int):
        """
        Creaza statistici pentru un jucator
        :param id: id-ul unic al jucatorului
        :param numar_meciuri: numarul de meciuri in care aceste a jucat
        :return: statistica jucatorului cu id-ul dat
        """
        jucator = self.__jucator_repo.find(id)
        if jucator is not None:
            mvp = self.__mvp_repo.create_mvp(jucator, numar_meciuri)
            return mvp
        else:
            return None