package service;

import domain.Tuple;
import domain.Utilizator;
import domain.Prietenie;
import domain.validators.PrietenieValidator;
import domain.validators.ValidationException;
import domain.validators.Validator;
import repository.file.PrietenieRepository;
import repository.file.UtilizatorRepository;
import repository.memory.InMemoryRepository;

import java.time.LocalDate;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import service.Graph;

public class ServiceUtilizator {
    private UtilizatorRepository repo;
    private PrietenieRepository repoPrietenie;

    public ServiceUtilizator(UtilizatorRepository repo, PrietenieRepository repoPrietenie) {
        this.repo = repo;
        this.repoPrietenie = repoPrietenie;
    }

    public void addUtilizator(String nume1, String nume2, long id) {
        try{
            Utilizator user = new Utilizator(nume1, nume2);
            user.setId(id);
            this.repo.save(user);
        } catch (ValidationException e){
            throw new ValidationException(e.getMessage());
        }
    }

    public void deleteUtilizator(long id) {
        if (repo.findOne(id) == null) {
            throw new ValidationException("Utilizator negasit");
        }
        try {
            List<Prietenie> prieteniiDeSters = new ArrayList<>();
            for (Prietenie prietenie : this.repoPrietenie.findAll()) {
                if (prietenie.getId1() == id || prietenie.getId2() == id) {
                    prieteniiDeSters.add(prietenie);
                }
            }
            for (Prietenie prietenie : prieteniiDeSters) {
                this.repoPrietenie.delete(prietenie.getId());
            }
            this.repo.delete(id);
        } catch (ValidationException e) {
            throw new ValidationException(e.getMessage());
        }
    }

    public Iterable<Utilizator> all_utilizators() {
        return this.repo.findAll();
    }

    public void addPrietenie(long id1, long id2)
    {
       try{
           Prietenie prietenie = new Prietenie(id1, id2, LocalDate.now());
           prietenie.setId(new Tuple<Long, Long>(id1, id2));
           PrietenieValidator.validare_cu_repo(prietenie,repoPrietenie, repo);
           this.repoPrietenie.save(prietenie);
       } catch (ValidationException e){
           throw new ValidationException(e.getMessage());
       }
    }

    public void deletePrietenie(long id1, long id2)
    {
        try{
            Prietenie prietenie = this.repoPrietenie.findOne(new Tuple<Long,Long>(id1, id2));
            if(prietenie == null)
                throw new ValidationException("Prietenie negasita");
            this.repoPrietenie.delete(prietenie.getId());
        } catch (ValidationException e){
            throw new ValidationException(e.getMessage());
        }
    }

    public Iterable<Prietenie> all_prietenii()
    {
        return this.repoPrietenie.findAll();
    }

    public int componente_conexe(){
        int numarNoduri = 0;
        for(Utilizator utilizator: repo.findAll())
        {
            numarNoduri++;
        }
        Graph graph = new Graph(numarNoduri);
        for (Prietenie prietenie : repoPrietenie.findAll()) {
            graph.addEdge(prietenie.getId1(), prietenie.getId2());
        }
        return graph.countConnectedComponents();
    }

    public List<Long> getLongestPathComponent() {
        int numarNoduri = 0;
        for (Utilizator utilizator : repo.findAll()) {
            numarNoduri++;
        }
        Graph graph = new Graph(numarNoduri);
        for (Prietenie prietenie : repoPrietenie.findAll()) {
            graph.addEdge(prietenie.getId1(), prietenie.getId2());
        }
        return graph.findLongestPathComponent();
    }


    public List<Long> prieteni(long id1)
    {
        List<Long> prieteni = new java.util.ArrayList<>();
        for(Prietenie prietenie: repoPrietenie.findAll())
        {
            if(prietenie.getId1() == id1)
                prieteni.add(prietenie.getId2());
        }
        return prieteni;
    }
}
