

class MVPCandidate:
    def __init__(self, jucator, numar_meciuri):
        self.__jucator = jucator
        self.__numar_meciuri = numar_meciuri

    def get_jucator(self):
        return self.__jucator

    def get_numar_meciuri(self):
        return self.__numar_meciuri

    def get_points_avarage(self):
        return self.get_jucator().get_puncte() / self.get_numar_meciuri()

    def __str__(self):
        return str(self.get_jucator().get_id()) + " || " + str(self.get_jucator().get_nume())+" || " + str(self.get_points_avarage())