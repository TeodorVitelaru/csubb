package repository.database;

import domain.Utilizator;
import domain.validators.Validator;
import repository.Repository;

import java.sql.*;
import java.util.HashSet;
import java.util.Optional;
import java.util.Set;

public class UtilizatorDbRepository implements Repository<Long, Utilizator> {
    private String url;
    private String username;
    private String password;
    private Validator<Utilizator> validator;

    public UtilizatorDbRepository(String url, String username, String password, Validator<Utilizator> validator)
    {
        this.url = url;
        this.username = username;
        this.password = password;
        this.validator = validator;
    }


    @Override
    public Optional<Utilizator> findOne(Long aLong) {
        Utilizator utilizator = null;
        try (Connection connection = DriverManager.getConnection(url, username, password);
             PreparedStatement statement = connection.prepareStatement("SELECT * from users WHERE id = ?");
        ) {
            statement.setLong(1, aLong);
            ResultSet resultSet = statement.executeQuery();
            if (resultSet.next()) {
                Long id = resultSet.getLong("id");
                String firstName = resultSet.getString("first_name");
                String lastName = resultSet.getString("last_name");

                utilizator = new Utilizator(firstName, lastName);
                utilizator.setId(id);
            }
            resultSet.close();

        } catch (SQLException e) {
            e.printStackTrace();
        }

        return Optional.ofNullable(utilizator);
    }

    @Override
    public Iterable<Utilizator> findAll() {
        Set<Utilizator> users = new HashSet<>();
        try(Connection connection = DriverManager.getConnection(url, username, password);
            PreparedStatement statement = connection.prepareStatement("SELECT * from users");
            ResultSet resultSet = statement.executeQuery()) {

            while(resultSet.next())
            {
                Long id = resultSet.getLong("id");
                String firstName = resultSet.getString("first_name");
                String lastName = resultSet.getString("last_name");

                Utilizator utilizator = new Utilizator(firstName, lastName);
                utilizator.setId(id);
                users.add(utilizator);
            }
            return users;
           } catch (SQLException e) {
            e.printStackTrace();
        }
        return users;
    }

    @Override
    public Optional<Utilizator> save(Utilizator entity) {
        if(entity==null)
            throw new IllegalArgumentException("ENTITY CANNOT BE NULL");
        validator.validate(entity);
        try (Connection connection = DriverManager.getConnection(url, username, password);
             PreparedStatement statement = connection.prepareStatement("INSERT INTO users(first_name, last_name) VALUES (?, ?)")) {
            statement.setString(1, entity.getFirstName());
            statement.setString(2, entity.getLastName());
            statement.executeUpdate();

        } catch (SQLException e) {
            e.printStackTrace();
        }

        return Optional.of(entity);

    }

    @Override
    public Optional<Utilizator> delete(Long aLong) {
        try(Connection connection = DriverManager.getConnection(url, username, password);
            PreparedStatement statement = connection.prepareStatement("DELETE FROM users WHERE id = ?")) {
            statement.setLong(1, aLong);
            statement.executeUpdate();
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return Optional.empty();
    }

    @Override
    public Optional<Utilizator> update(Utilizator entity) {
        int rez = -1;
        try(Connection connection = DriverManager.getConnection(url, username, password);
            PreparedStatement statement = connection.prepareStatement("UPDATE users SET first_name = ?, last_name = ? WHERE id = ?")) {
            statement.setString(1, entity.getFirstName());
            statement.setString(2, entity.getLastName());
            statement.setLong(3, entity.getId());
            rez = statement.executeUpdate();
        } catch (SQLException e) {
            e.printStackTrace();
        }
        if(entity==null)
            throw new IllegalArgumentException("ENTITY CANNOT BE NULL");
        validator.validate(entity);
        if(rez > 0)
            return null;
        return Optional.of(entity);

    }
}
