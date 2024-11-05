package repository.file;

import domain.Entity;
import domain.Utilizator;
import domain.validators.Validator;
import repository.Repository;
import repository.memory.InMemoryRepository;

import java.io.*;
import java.nio.Buffer;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public abstract class AbstractFileRepository<ID, E extends Entity<ID>> extends InMemoryRepository<ID, E>{
    private String filename;

    public AbstractFileRepository(Validator<E> validator, String fileName) {
        super(validator);
        this.filename=fileName;
        loadData();
    }

    private void loadData() {
        try {
            var fileReader = new Scanner(new File(this.filename));
            while (fileReader.hasNextLine()) {
                String input = fileReader.nextLine();
                super.save(createEntity(input));
            }
            fileReader.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public abstract E createEntity(String line);
    public abstract String saveEntity(E entity);

    @Override
    public E findOne(ID id) {
        return super.findOne(id);
    }

    @Override
    public Iterable<E> findAll() {
        return super.findAll();
    }

    @Override
    public E save(E entity) {
        E e = super.save(entity);
        if (e == null)
            writeToFile();
        return e;
    }

    private void writeToFile() {

        try  ( BufferedWriter writer = new BufferedWriter(new FileWriter(filename))){
            for (E entity: entities.values()) {
                String ent = saveEntity(entity);
                writer.write(ent);
                writer.newLine();
            }
        } catch (IOException e) {
            throw new RuntimeException(e);
        } catch (Exception e) {
            e.printStackTrace();
        }

    }

    @Override
    public E delete(ID id) {
        E deletedEntity = super.delete(id); // Use the inherited method from InMemoryRepository
        if (deletedEntity != null) {
            writeToFile(); // Update the file after deletion
        }
        return deletedEntity;
    }

    @Override
    public E update(E entity) {
        E updatedEntity = super.update(entity); // Use the inherited method from InMemoryRepository
        if (updatedEntity == null) {
            writeToFile(); // Update the file after the update
        }
        return updatedEntity;
    }
}
