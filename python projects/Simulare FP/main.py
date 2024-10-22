from repository.jucator_repo import JucatorFileRepository
from repository.mvp_repo import MvpInMemoryRepository
from service.jucator_service import JucatorController
from service.mvp_service import MvpController
from ui.consola import Consola

jucator_repo = JucatorFileRepository("data/jucatori.txt")
mvp_repo = MvpInMemoryRepository()
jucator_service = JucatorController(jucator_repo)
mvp_service = MvpController(mvp_repo, jucator_repo)
consola = Consola(jucator_service, mvp_service)

consola.run()