package service;

import domain.Tuple;
import domain.Utilizator;
import domain.Prietenie;
import domain.validators.PrietenieValidator;
import domain.validators.ValidationException;
import repository.Repository;
import repository.database.PrietenieDbRepository;
import repository.file.PrietenieRepository;
import repository.file.UtilizatorRepository;

import java.time.LocalDate;
import java.util.ArrayList;
import java.util.List;
import java.util.Optional;

import static java.lang.Math.max;
import static java.lang.Math.min;


public class ServiceUtilizator {
    private Repository repo;
    private PrietenieDbRepository repoPrietenie;

    public ServiceUtilizator(Repository repo, PrietenieDbRepository repoPrietenie) {
        this.repo = repo;
        this.repoPrietenie = repoPrietenie;
    }

    public void addUtilizator(String nume1, String nume2) {
        try{
            Utilizator user = new Utilizator(nume1, nume2);
            this.repo.save(user);
        } catch (ValidationException e){
            throw new ValidationException(e.getMessage());
        }
    }

    public void deleteUtilizator(long id) {
        if (repo.findOne(id).isEmpty()) {
            throw new ValidationException("Utilizator negasit");
        }
        try {
            List<Prietenie> prieteniiDeSters = new ArrayList<>();
            this.repoPrietenie.findAll().forEach(prietenie ->{
                if (prietenie.getId1() == id || prietenie.getId2() == id) {
                    prieteniiDeSters.add(prietenie);
                }
            });
            prieteniiDeSters.forEach( prietenie -> {
                this.repoPrietenie.delete(prietenie.getId());
            });
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
           prietenie.setId(new Tuple<Long, Long>(min(id1, id2), max(id2, id1)));
           PrietenieValidator.validare_cu_repo(prietenie,repoPrietenie, repo);
           this.repoPrietenie.save(prietenie);
       } catch (ValidationException e){
           throw new ValidationException(e.getMessage());
       }
    }

    public void deletePrietenie(long id1, long id2)
    {
        if(this.repoPrietenie.findOne(new Tuple<Long,Long>(min(id1, id2), max(id2, id1)) ).isEmpty())
            throw new ValidationException("Prietenie negasita");
        try{
            this.repoPrietenie.delete(new Tuple<Long, Long>(min(id1, id2), max(id1, id2)));
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
        for(Object utilizator: repo.findAll())
        {
            numarNoduri++;
        }
        Graph graph = new Graph(numarNoduri);
        repoPrietenie.findAll().forEach(prietenie -> {
            graph.addEdge(prietenie.getId1(), prietenie.getId2());
        });
        return graph.countConnectedComponents();
    }

    public List<Long> getLongestPathComponent() {
        int numarNoduri = 0;
        for (Object utilizator : repo.findAll()) {
            numarNoduri++;
        }
        Graph graph = new Graph(numarNoduri);
        repoPrietenie.findAll().forEach(prietenie -> {
            graph.addEdge(prietenie.getId1(), prietenie.getId2());
        });

        return graph.findLongestPathComponent();
    }


    public List<Long> prieteni(long id1)
    {
        List<Long> prieteni = new java.util.ArrayList<>();
        repoPrietenie.findAll().forEach(prietenie -> {
            if(prietenie.getId1() == id1)
                prieteni.add(prietenie.getId2());
            else if(prietenie.getId2() == id1)
                prieteni.add(prietenie.getId1());
        });
        return prieteni;
    }
}
