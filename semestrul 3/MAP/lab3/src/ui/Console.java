package ui;

import domain.Prietenie;
import domain.Utilizator;
import domain.validators.ValidationException;
import service.ServiceUtilizator;

import java.util.Scanner;

public class Console {
    private ServiceUtilizator serviceUtilizator;

    public Console(ServiceUtilizator serviceUtilizator) {
        this.serviceUtilizator = serviceUtilizator;
    }

    public void start()
    {
        boolean gata=false;
        while(!gata)
        {
            System.out.println("\nMENU:\n" +
                                "1.User\n" +
                                "2.Prietenii\n" +
                                "4.Iesire\n" +
                                "5.Componente_conexe\n" +
                                "6.Drumuri\n");
            System.out.print("Enter your choice: ");
            Scanner in = new Scanner(System.in);

            String s = in.nextLine();

            //pentru user
            if(s.equals("1"))
            {
                System.out.print("1. adaugare user\n"+
                                "2.delete user\n"+
                                "3.afisare users\n"+
                                "4.exit\n");
                String s1 = in.nextLine();
                switch(s1){
                    case "1":
                        adaugare_user_ui();
                        break;
                        case "2":
                            stergere_user_ui();
                            break;
                            case "3":
                                afisare_utilizatori_ui();
                            case "4":
                                break;
                }
            }
            //pentru prietenii
            else if(s.equals("2"))
            {
                System.out.print("1. adaugare prietenie\n"+
                        "2.delete prietenie\n"+
                        "3.afisare prietenii\n"+
                        "4.exit\n");
                String s1 = in.nextLine();
                switch(s1){
                    case "1":
                        adaugare_prietenie_ui();
                        break;
                        case "2":
                            stergere_prietenie_ui();
                            break;
                            case "3":
                                afisare_prietenii_ui();
                            case "4":
                                break;
                }
            }
            else if(s.equals("4"))
            {
                gata=true;
            }
            else if(s.equals("5"))
            {
               int numar = serviceUtilizator.componente_conexe();
                System.out.println("Numarul de componente conexe este: "+numar);

            } else if(s.equals("6"))
            {
                System.out.println(serviceUtilizator.getLongestPathComponent());

            }
        }
    }

    public void afisare_utilizatori_ui()
    {
        for(Utilizator utilizator: serviceUtilizator.all_utilizators())
        {
            System.out.println(utilizator + ", " + serviceUtilizator.prieteni(utilizator.getId()).toString() + "}");
        }

    }

    public void afisare_prietenii_ui()
    {
        for(Prietenie prietenie: serviceUtilizator.all_prietenii())
        {
            System.out.println(prietenie);
        }
    }

    public void adaugare_user_ui()
    {
        try{
            System.out.print("Enter first name: ");
            Scanner in = new Scanner(System.in);
            String first = in.nextLine();
            System.out.print("Enter last name: ");
            Scanner in2 = new Scanner(System.in);
            String last = in2.nextLine();
            System.out.print("ID: ");
            Scanner in3 = new Scanner(System.in);
            String id_string = in3.nextLine();
            if(id_string.equals(""))
                throw new ValidationException("id ul este invalid");
            Long id = Long.parseLong(id_string);
            this.serviceUtilizator.addUtilizator(first, last, id);
            System.out.println("SUCCES!USER ADAUGAT");
        } catch (ValidationException e)
        {
            System.out.println(e.getMessage());
        } catch (NumberFormatException e) {
            System.out.println(e.getMessage());
        }
    }

    public void stergere_user_ui()
    {
        System.out.print("id de sters:");
        Scanner in = new Scanner(System.in);
        Long id;
        try {
            id = in.nextLong();
        } catch (Exception e) {
            System.out.println("ID invalid");
            return;
        }
        try{
            this.serviceUtilizator.deleteUtilizator(id);
            System.out.println("SUCCES!USER STERGERE");
        }catch (ValidationException e)
        {
            System.out.println(e.getMessage());
        } catch (IllegalArgumentException e) {
            System.out.println(e.getMessage());
        }
    }

    public void adaugare_prietenie_ui()
    {
        System.out.print("id de prietenie:");
        Scanner in = new Scanner(System.in);
        Long id1 = Long.parseLong(in.nextLine());
        System.out.print("id de prietenie:");
        Long id2 = Long.parseLong(in.nextLine());
        try {
            this.serviceUtilizator.addPrietenie(id1, id2);
            System.out.println("SUCCES!PRIETENIE ADAUGATA\n");
        } catch (ValidationException e)
        {
            System.out.println(e.getMessage());
        }  catch (NumberFormatException e) {
            System.out.println("ID invalid");
        }
    }

    public void stergere_prietenie_ui()
    {
        try {
            System.out.print("id de prietenie:");
            Scanner in = new Scanner(System.in);
            String id1_string = in.nextLine();
            Long id1 = Long.parseLong(id1_string);
            System.out.print("id de prietenie:");
            Scanner in2 = new Scanner(System.in);
            String id2_string = in2.nextLine();
            Long id2 = Long.parseLong(id2_string);
            this.serviceUtilizator.deletePrietenie(id1, id2);
            System.out.println("SUCCES!PRIETENIE STERGERE\n");
        } catch (ValidationException e) {
            System.out.println(e.getMessage());
        } catch (NumberFormatException e) {
            System.out.println("ID invalid");
        }


    }
}


