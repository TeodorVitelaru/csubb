from domain.validare import MelodieValidator
from repo.melodie_repo import MelodieFileRepository
from service.melodie_service import MelodieController
from ui.consola import Consola

melodie_repo = MelodieFileRepository("data/melodii.txt")
melodie_validator = MelodieValidator()
melodie_controller = MelodieController(melodie_repo, melodie_validator)
consola = Consola(melodie_controller)
consola.run()