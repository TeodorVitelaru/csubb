from domain.MVPCandidate import MVPCandidate


class MvpInMemoryRepository:
    def __init__(self):
        pass

    def create_mvp(self, jucator, numar_meciuri):
        """
        Crearea de statistici pt un jucator
        :param jucator: jucatorul caruia ii facem statistica
        :param numar_meciuri: numarul de meciuri jucate
        :return:
        """
        return MVPCandidate(jucator, numar_meciuri)