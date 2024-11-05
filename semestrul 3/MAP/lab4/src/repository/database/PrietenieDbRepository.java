package repository.database;

import domain.Prietenie;
import domain.Tuple;
import domain.validators.Validator;
import repository.Repository;

import java.sql.*;
import java.time.LocalDate;
import java.util.HashSet;
import java.util.Optional;
import java.util.Set;

import static java.lang.Math.max;
import static java.lang.Math.min;

public class PrietenieDbRepository implements Repository<Tuple<Long, Long>, Prietenie> {
    private String url;
    private String username;
    private String password;
    private Validator<Prietenie> validator;

    public PrietenieDbRepository(String url, String username, String password, Validator<Prietenie> validator) {
        this.url = url;
        this.username = username;
        this.password = password;
        this.validator = validator;
    }

    @Override
    public Optional<Prietenie> findOne(Tuple<Long, Long> longLongTuple) {
        if (longLongTuple == null)
            throw new IllegalArgumentException("id must not be null");
        Prietenie prietenie = null;
        try(Connection connection = DriverManager.getConnection(url, username, password);
            PreparedStatement statement = connection.prepareStatement("SELECT * from friendships WHERE id1 = ? AND id2 = ?");)
        {
            statement.setLong(1, longLongTuple.getLeft());
            statement.setLong(2, longLongTuple.getRight());
            ResultSet resultSet = statement.executeQuery();

            if(resultSet.next())
            {
                Long id1 = min(resultSet.getLong("id1"), resultSet.getLong("id2"));
                Long id2 = max(resultSet.getLong("id1"), resultSet.getLong("id2"));
                LocalDate date = resultSet.getDate("date").toLocalDate();
                prietenie = new Prietenie(id1, id2, date);
            }
            resultSet.close();
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return Optional.ofNullable(prietenie);
    }

    @Override
    public Iterable<Prietenie> findAll() {
        Set<Prietenie> prietenii = new HashSet<>();
        try(Connection connection = DriverManager.getConnection(url, username, password);
            PreparedStatement statement = connection.prepareStatement("SELECT * from friendships");
            ResultSet resultSet = statement.executeQuery())
        {
            while(resultSet.next())
            {
                Long id1 = resultSet.getLong("id1");
                Long id2 = resultSet.getLong("id2");
                LocalDate date = resultSet.getDate("date").toLocalDate();
                Prietenie prietenie = new Prietenie(id1, id2, date);
                prietenie.setId(new Tuple<>(id1, id2));
                prietenii.add(prietenie);
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return prietenii;
    }

    @Override
    public Optional<Prietenie> save(Prietenie entity) {
        if(entity == null)
        {
            throw new IllegalArgumentException("entity must not be null");
        }
        validator.validate(entity);
        try(Connection connection = DriverManager.getConnection(url, username, password);
             PreparedStatement statement = connection.prepareStatement("INSERT INTO friendships (id1, id2, date) VALUES (?, ?, ?)"))
        {
            statement.setLong(1, entity.getId1());
            statement.setLong(2, entity.getId2());
            statement.setDate(3, Date.valueOf(entity.getDate()));
            statement.executeUpdate();
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return Optional.of(entity);
    }

    @Override
    public Optional<Prietenie> delete(Tuple<Long, Long> longLongTuple) {
        if(longLongTuple == null)
        {
            throw new IllegalArgumentException("id must not be null");
        }
        Optional<Prietenie> prietenie = findOne(longLongTuple);
        if(prietenie.isEmpty())
        {
            throw new IllegalArgumentException("entitate indisponibil");
        }
        try(Connection connection = DriverManager.getConnection(url, username, password);
            PreparedStatement statement = connection.prepareStatement("DELETE FROM friendships WHERE id1 = ? AND id2 = ?"))
        {
            statement.setLong(1, longLongTuple.getLeft());
            statement.setLong(2, longLongTuple.getRight());
            statement.executeUpdate();
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return prietenie;
    }

    @Override
    public Optional<Prietenie> update(Prietenie entity) {
        if(entity == null)
        {
            throw new IllegalArgumentException("entity must not be null");
        }
        validator.validate(entity);
        try(Connection connection = DriverManager.getConnection(url, username, password);
            PreparedStatement statement = connection.prepareStatement("UPDATE friendships SET date = ? WHERE id1 = ? AND id2 = ?"))
        {
            statement.setDate(1, Date.valueOf(entity.getDate()));
            statement.setLong(2, entity.getId1());
            statement.setLong(3, entity.getId2());
            statement.executeUpdate();
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return Optional.of(entity);
    }
}
