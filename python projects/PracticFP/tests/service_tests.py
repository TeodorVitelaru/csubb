from unittest import TestCase

from domain.validare import MelodieValidator
from repo.melodie_repo import MelodieFileRepository
from service.melodie_service import MelodieController
from utils.file_utils import clear_file_content, copy_file_content


class TestService(TestCase):
    def setUp(self):
        clear_file_content("test_melodii.txt")
        copy_file_content("default_melodii.txt", "test_melodii.txt")
        self.test_repo = MelodieFileRepository("test_melodii.txt")
        self.validare_test = MelodieValidator()
        self.test_controller = MelodieController(self.test_repo, self.validare_test)

    def test_modificare_melodie(self):
        lista_veche = self.test_controller.get_all_melodii()
        assert lista_veche[0].get_gen() == 'Rock'
        self.test_controller.modificare_melodie('Crying', 'teodor', 'Jazz', '01.01.2021')
        assert self.test_repo.size() == 5
        lista_noua = self.test_controller.get_all_melodii()
        assert lista_noua[0].get_gen() == 'Jazz'


    def test_adaugare_melodie(self):
        lista_veche = self.test_controller.get_all_melodii()
        assert len(lista_veche) == 5
        self.test_controller.adaugare_melodie('asa', 'eu', 'Jazz', '01.01.2019')
        lista_noua = self.test_controller.get_all_melodii()
        assert len(lista_veche) == 5

    def test_generare_melodie(self):
        artisti = ['eu', 'tu', 'noi']
        titluri = ['eu', 'tu', 'noi']
        melodie = self.test_controller.generare_melodii(artisti, titluri)
        assert (melodie.get_gen() in ["Rock", "Jazz", "Pop"]) == True
        assert (melodie.get_artist() in ['eu', 'tu', 'noi']) == True
        assert (melodie.get_titlu() in ['eu', 'tu', 'noi']) == True
        assert melodie.get_data() == "01.01.2020"

    def test_exporta_melodie(self):
        self.test_controller.exporta_melodii("test_export.txt")
        assert len(self.test_repo.read_from_file()) == 5

