from unittest import TestCase

from repository.jucator_repo import JucatorFileRepository
from repository.mvp_repo import MvpInMemoryRepository
from utils.file_utils import clear_file_content, copy_file_content


class TestRepoJucator(TestCase):
    def setUp(self):
        clear_file_content("test_jucatori.txt")
        copy_file_content("default_jucatori.txt", "test_jucatori.txt")
        self.test_repo = JucatorFileRepository("test_jucatori.txt")

    def test_read_from_file(self):
        assert len(self.test_repo.read_from_file()) == 6
        assert len(self.test_repo.read_from_file()) != 5

    def test_find(self):
        assert len(self.test_repo.read_from_file()) == 6
        jucator = self.test_repo.find("MH9")
        assert jucator.get_nume() == 'david wade'
        assert jucator.get_puncte() == 210
        assert self.test_repo.find("123") is None
        assert self.test_repo.find("GSW30") is not None


class TestMvpRepo(TestCase):
    def setUp(self):
        clear_file_content("test_jucatori.txt")
        copy_file_content("default_jucatori.txt", "test_jucatori.txt")
        self.jucator_repo = JucatorFileRepository("test_jucatori.txt")
        self.mvp_repo = MvpInMemoryRepository()

    def test_create_mvp(self):
        lista_jucatori = self.jucator_repo.get_all()
        mvp = self.mvp_repo.create_mvp(lista_jucatori[0],2 )
        assert mvp.get_jucator().get_nume() == "Stehpen Curry"
        assert mvp.get_points_avarage() == 89
        mvp1 =  self.mvp_repo.create_mvp(lista_jucatori[1], 3)
        assert mvp1.get_jucator().get_nume() == "david wade"
        assert mvp1.get_points_avarage() == 70

