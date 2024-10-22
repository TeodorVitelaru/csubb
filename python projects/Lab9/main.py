from domain.validare import ProblemaValidator, StudentValidator, NotaValidator
from repository.memory_repository_nota import NotaInMemoryRepository, NotaFileRepository
from repository.memory_repository_problema import ProblemaInMemoryRepository, ProblemaFileRepository
from repository.memory_repository_student import StudentInMemoryRepository, StudentFileRepository
from service.serivice_student import StudentController
from service.service_nota import NotaController
from service.service_problema import ProblemaController
from ui.consola import Consola

repository_student = StudentFileRepository("data/students.txt")
repository_problema = ProblemaFileRepository("data/problems.txt")
repository_nota = NotaFileRepository("data/notari.txt", repository_student, repository_problema)
validator_student = StudentValidator()
validator_problema = ProblemaValidator()
validator_nota = NotaValidator
student_controller = StudentController(repository_student, validator_student)
problema_controller = ProblemaController(repository_problema, validator_problema)
nota_controller = NotaController(repository_nota, validator_nota, repository_student, repository_problema)
console = Consola(student_controller, problema_controller, nota_controller)
console.run()