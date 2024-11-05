package domain.validators;


import domain.Utilizator;

public class UtilizatorValidator implements Validator<Utilizator> {
    @Override
    public void validate(Utilizator entity) throws ValidationException {
        //TODO: implement method validate
        if(entity.getFirstName().equals("") || entity.getLastName().equals(""))
            throw new ValidationException("Utilizatorul nu este valid");
    }
}
