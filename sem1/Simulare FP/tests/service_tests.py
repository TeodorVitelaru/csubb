from unittest import TestCase

from repository.jucator_repo import JucatorFileRepository
from repository.mvp_repo import MvpInMemoryRepository
from service.jucator_service import JucatorController
from service.mvp_service import MvpController
from utils.file_utils import clear_file_content, copy_file_content


class TestServiceJucator(TestCase):
    def setUp(self):
        clear_file_content("test_jucatori.txt")
        copy_file_content("default_jucatori.txt", "test_jucatori.txt")
        self.test_repo = JucatorFileRepository("test_jucatori.txt")
        self.test_service = JucatorController(self.test_repo)

    def test_cautare_dupa_pozitie(self):
        lista_jucatori_gasiti = self.test_service.catuare_dupa_pozitie("center")
        assert len(lista_jucatori_gasiti) == 2
        jucator1 = lista_jucatori_gasiti[0]
        jucator2 = lista_jucatori_gasiti[1]
        assert jucator1.get_nume() == 'Teodor Bis'
        assert jucator1.get_pozitie() == 'center'
        assert jucator2.get_nume() == 'MAtei EU'
        assert jucator2.get_puncte() == 145
        lista_noua = self.test_service.catuare_dupa_pozitie("point_guard")
        assert len(lista_noua) == 2


class TestServiceMVP(TestCase):
    def setUp(self):
        clear_file_content("test_jucatori.txt")
        copy_file_content("default_jucatori.txt", "test_jucatori.txt")
        self.jucator_repo = JucatorFileRepository("test_jucatori.txt")
        self.mvp_repo = MvpInMemoryRepository()
        self.mvp_serivce = MvpController(self.mvp_repo, self.jucator_repo)

    def test_evolutie(self):
        test_mvp = self.mvp_serivce.evolutie("GSW30", 2)
        assert test_mvp.get_jucator().get_nume() == "Stehpen Curry"
        assert test_mvp.get_numar_meciuri() == 2
        assert test_mvp.get_points_avarage() == 89
        mvp1 = self.mvp_serivce.evolutie("asdas", 2)
        assert mvp1 is None