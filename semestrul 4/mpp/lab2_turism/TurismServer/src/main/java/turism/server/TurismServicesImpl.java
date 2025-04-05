package turism.server;

import turism.model.Client;
import turism.model.Excursie;
import turism.model.Rezervare;
import turism.model.User;
import turism.persistence.ClientRepo;
import turism.persistence.ExcursieRepo;
import turism.persistence.RezervareRepo;
import turism.persistence.UserRepo;
import turism.services.ITurismObserver;
import turism.services.ITurismServices;

import java.time.LocalDateTime;
import java.util.List;
import java.util.Map;
import java.util.Optional;
import java.util.concurrent.ConcurrentHashMap;
import java.util.stream.Collectors;
import java.util.stream.StreamSupport;

import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;


public class TurismServicesImpl implements ITurismServices {
    private ClientRepo clientRepo;
    private ExcursieRepo excursieRepo;
    private RezervareRepo rezervareRepo;
    private UserRepo userRepo;
    private Map<Long, ITurismObserver> loggedUsers;
    private static Logger logger = LogManager.getLogger(TurismServicesImpl.class);

    public TurismServicesImpl(ClientRepo clientRepo, ExcursieRepo excursieRepo, RezervareRepo rezervareRepo, UserRepo userRepo) {
        this.clientRepo = clientRepo;
        this.excursieRepo = excursieRepo;
        this.rezervareRepo = rezervareRepo;
        this.userRepo = userRepo;
        this.loggedUsers = new ConcurrentHashMap<>();
    }


    public synchronized Optional<Client> addClient(Client client) {
        Optional<Client> client2 = clientRepo.save(client);
        return client2;
    }


    public synchronized Client findClientByNameAndPhoneNumber(String name, String phoneNumber) {
        Client client =  clientRepo.findByNumeAndTelefon(name, phoneNumber);
        return client;
    }

    public synchronized List<Excursie> getAllExcursieByDestinationAndDate(String destination, LocalDateTime date1, LocalDateTime date2) {
        List<Excursie> excursii = excursieRepo.findByDestinationAndDate(destination, date1, date2);
        return excursii;
    }


    public synchronized List<Excursie> getAllExcursie() {
        Iterable<Excursie> iterable = excursieRepo.findAll();
        return StreamSupport.stream(iterable.spliterator(), false)
                .collect(Collectors.toList());
    }


    public synchronized List<Rezervare> getRezervariByExcursie(Excursie excursie) {
        logger.info("Finding rezervari for excursion {}", excursie);
        List<Rezervare> rezervari = rezervareRepo.findByExcursie(excursie);
        logger.info("Found rezervari for excursion {}: {}", excursie, rezervari);
        return rezervari;
    }

    public synchronized List<Rezervare> getAllRezervari() {
        logger.info("Getting all rezervari");
        Iterable<Rezervare> iterable = rezervareRepo.findAll();
        List<Rezervare> rezervari = StreamSupport.stream(iterable.spliterator(), false)
                .collect(Collectors.toList());
        logger.info("Found rezervari: {}", rezervari);
        return rezervari;
    }

    public synchronized int getLocuriOcupateForExcursie(Excursie excursie) {
        logger.info("Calculating occupied seats for excursion {}", excursie);
        int rezervari = 0;
        List<Rezervare> rezervariList = rezervareRepo.findByExcursie(excursie);
        for (Rezervare rezervare : rezervariList) {
            rezervari += rezervare.getNrBilete();
        }
        logger.info("Occupied seats for excursion {}: {}", excursie, rezervari);
        return rezervari;
    }

    public synchronized Rezervare addRezervare(Excursie excursie, Client client, int nrBilete, User user) {
        logger.info("Adding rezervare for client {} with nrBilete {}", client, nrBilete);
        Rezervare rezervare = new Rezervare(excursie, client, nrBilete, user);
        Optional<Rezervare> rezervareOuput = rezervareRepo.save(rezervare);
        logger.info("Rezervare added successfully.");
        return rezervareOuput.orElse(null);
    }

    public synchronized User login(User user, ITurismObserver client) throws Exception {
        logger.traceEntry("login({}, {}, {})", user.getId(), user.getUsername(), user.getPassword());

        User userR = userRepo.findByUsernameAndPassword(user.getUsername(), user.getPassword());
        if (userR != null) {
            if(loggedUsers.get(userR.getId()) != null)
                throw new Exception("User already logged in.");
            loggedUsers.put(userR.getId(), client);
        }
        //loggedUsers.put(username, userR);
        logger.info("User {} {} logged in successfully.", userR.getId(), userR.getUsername());
        return userR;
    }

    public synchronized void logout(User user, ITurismObserver client) throws Exception {
        logger.traceEntry("logout({})", user);
        ITurismObserver localClient = loggedUsers.remove(user.getId());
        if (localClient == null)
            throw new Exception("User " + user.getUsername() + " is not logged in.");
        logger.info("User {} logged out successfully.", user.getUsername());
    }

    private final int defaultThreadsNo = 3;
}
