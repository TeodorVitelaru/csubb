package repository.file;

import domain.Prietenie;
import domain.Tuple;
import domain.Utilizator;
import domain.validators.Validator;
import repository.Repository;


import java.time.LocalDate;
import java.util.Arrays;
import java.util.List;
import java.util.Map;

public class PrietenieRepository extends AbstractFileRepository<Tuple<Long, Long>, Prietenie> {

    public PrietenieRepository(String filename, Validator<Prietenie> validator) {
        super(validator, filename);
    }

    @Override
    public Prietenie createEntity(String line) {
        List<String> values = Arrays.asList(line.split(";"));
        long id1 = Long.parseLong(values.get(0));
        long id2 = Long.parseLong(values.get(1));
        LocalDate date = LocalDate.parse(values.get(2));
        Prietenie prietenie = new Prietenie(id1, id2, date);
        prietenie.setId(new Tuple<>(id1, id2));

        return prietenie;
   }

   public void adauga_in_lista()
   {

   }

    @Override
    public String saveEntity(Prietenie entity) {
        return entity.getId1() + ";" + entity.getId2() + ";" + entity.getDate();
    }
}
