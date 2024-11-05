package domain.validators;

import domain.Prietenie;
import domain.Tuple;
import repository.Repository;
import repository.file.PrietenieRepository;
import repository.file.UtilizatorRepository;

public class PrietenieValidator implements Validator<Prietenie> {
    @Override
    public void validate(Prietenie prietenie) {
        String erori = "";
        if(prietenie.getId1() == prietenie.getId2()){
            erori += "invalid friendship";

        }
        if(prietenie.getDate() == null )
            erori += "invalid date";
        if(!erori.equals(""))
        {
            throw new ValidationException(erori);
        }
    }
    public static void validare_cu_repo(Prietenie prietenie, Repository repo2, Repository repo) {
        String erori = "";
        if(repo.findOne(prietenie.getId1()).isEmpty())
            erori += "invalid id";
        if(repo.findOne(prietenie.getId2()).isEmpty())
            erori += "invalid id";
        if(repo2.findOne(new Tuple<Long, Long>(prietenie.getId2(), prietenie.getId1())).isPresent())
            erori += "deja prieteni";
        if(prietenie == null)
            erori += "invalid friendship";
        if(!erori.isEmpty())
            throw new ValidationException(erori);

    }
}
