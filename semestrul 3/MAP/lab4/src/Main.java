import domain.validators.PrietenieValidator;
import domain.validators.UtilizatorValidator;
import repository.database.PrietenieDbRepository;
import repository.database.UtilizatorDbRepository;
import service.ServiceUtilizator;
import ui.Console;




public class Main {
    public static void main(String[] args) {
        //UtilizatorRepository repo = new UtilizatorRepository(new UtilizatorValidator(), "D:/jocuri/java//lab4/src/users.txt");
        UtilizatorDbRepository repoDB = new UtilizatorDbRepository("jdbc:postgresql://localhost:5432/labMAP", "postgres", "postgres", new UtilizatorValidator());
        //PrietenieRepository repoPrietenie = new PrietenieRepository("D:/jocuri/java//lab4/src/prietenii.txt", (Validator<Prietenie>) new PrietenieValidator());
        PrietenieDbRepository repoDbPrietenie = new PrietenieDbRepository("jdbc:postgresql://localhost:5432/labMAP", "postgres", "postgres", new PrietenieValidator());
        //ServiceUtilizator service = new ServiceUtilizator(repo, repoPrietenie);
        ServiceUtilizator serviceDB = new ServiceUtilizator(repoDB, repoDbPrietenie);
        Console console = new Console(serviceDB);
        console.start();
        }
    }
