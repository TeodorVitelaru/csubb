import domain.Prietenie;
import domain.Utilizator;
import domain.validators.PrietenieValidator;
import domain.validators.UtilizatorValidator;
import domain.validators.Validator;
import repository.file.PrietenieRepository;
import repository.file.UtilizatorRepository;
import service.ServiceUtilizator;
import ui.Console;

import java.util.Iterator;
import java.util.List;
import java.util.Map;

//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {
        UtilizatorRepository repo = new UtilizatorRepository(new UtilizatorValidator(), "D:/jocuri/java//lab3/src/users.txt");
        PrietenieRepository repoPrietenie = new PrietenieRepository("D:/jocuri/java//lab3/src/prietenii.txt", (Validator<Prietenie>) new PrietenieValidator());
        ServiceUtilizator service = new ServiceUtilizator(repo, repoPrietenie);
        Console console = new Console(service);
        console.start();
        }
    }
