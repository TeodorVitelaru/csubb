package com.example.exam.repo;

import com.example.exam.domain.Page;
import com.example.exam.domain.Pageable;
import com.example.exam.domain.Show;

import java.sql.*;
import java.time.LocalDateTime;
import java.util.*;

public class ShowDbRepo implements PaginingRepository {
    private String url;
    private String username;
    private String password;

    public ShowDbRepo(String url, String username, String password) {
        this.url = url;
        this.username = username;
        this.password = password;
    }

    public Iterable<Show> findAll() {
        Set<Show> shows = new HashSet<>();
        try(Connection connection = DriverManager.getConnection(url, username, password);
            PreparedStatement statement = connection.prepareStatement("SELECT * from showuri");
            ResultSet resultSet = statement.executeQuery()) {

            while(resultSet.next())
            {
                int id = resultSet.getInt("id");
                String name = resultSet.getString("name");
                int durationMinutes = resultSet.getInt("durationminutes");
                LocalDateTime startDate = resultSet.getTimestamp("startdate").toLocalDateTime();
                int numberOfSeats = resultSet.getInt("numberofseats");
                LocalDateTime creationDate = resultSet.getTimestamp("creationdata").toLocalDateTime();


                Show show = new Show(name, durationMinutes, startDate, numberOfSeats, creationDate);
                show.setId(id);
                shows.add(show);
            }
            return shows;
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return shows;
    }

    public Optional<Show> save(Show entity) {
        if(entity==null)
            throw new IllegalArgumentException("ENTITY CANNOT BE NULL");
       // validator.validate(entity);
        try (Connection connection = DriverManager.getConnection(url, username, password);
             PreparedStatement statement = connection.prepareStatement("INSERT INTO showuri(name, durationminutes, startdate, numberofseats, creationdata) VALUES (?, ?, ?, ?, ?) RETURNING id");) {
            statement.setString(1, entity.getName());
            statement.setInt(2, entity.getDurationMinutes());
            statement.setTimestamp(3, Timestamp.valueOf(entity.getStartDate()));
            statement.setInt(4, entity.getNumberOfSeats());
            statement.setTimestamp(5, Timestamp.valueOf(entity.getCreationDate()));

            ResultSet resultSet = statement.executeQuery();
            if(resultSet.next())
            {
                int id = resultSet.getInt("id");
                entity.setId(id);
            }

        } catch (SQLException e) {
            e.printStackTrace();
        }

        return Optional.of(entity);
    }

    public List<Show> findAllOnPage(Connection connection, Pageable pageable) throws SQLException {
        List<Show> usersOnPage = new ArrayList<>();
        String sql = "SELECT id, name, durationMinutes, startDate, numberOfSeats, creationdata FROM showuri ORDER BY startDate LIMIT ? OFFSET ?";



        try(PreparedStatement statement = connection.prepareStatement(sql)) {
            statement.setInt(1, pageable.getPageSize());
            statement.setInt(2, pageable.getPageSize() * pageable.getPageNumber());
            ResultSet resultSet = statement.executeQuery();

            while(resultSet.next()) {
                int id = resultSet.getInt("id");
                String name = resultSet.getString("name");
                int durationMinutes = resultSet.getInt("durationminutes");
                LocalDateTime startDate = resultSet.getTimestamp("startdate").toLocalDateTime();
                int numberOfSeats = resultSet.getInt("numberofseats");
                LocalDateTime creationDate = resultSet.getTimestamp("creationdata").toLocalDateTime();


                Show show = new Show(name, durationMinutes, startDate, numberOfSeats, creationDate);
                show.setId(id);
                usersOnPage.add(show);
            }
        }
        return usersOnPage;
    }

    public List<Show> findAllOnPageReordonare(Connection connection, Pageable pageable) throws SQLException {
        List<Show> usersOnPage = new ArrayList<>();
        String sql = "SELECT id, name, durationMinutes, startDate, numberOfSeats, creationdata FROM showuri ORDER BY creationdata DESC LIMIT ? OFFSET ?";



        try(PreparedStatement statement = connection.prepareStatement(sql)) {
            statement.setInt(1, pageable.getPageSize());
            statement.setInt(2, pageable.getPageSize() * pageable.getPageNumber());
            ResultSet resultSet = statement.executeQuery();

            while(resultSet.next()) {
                int id = resultSet.getInt("id");
                String name = resultSet.getString("name");
                int durationMinutes = resultSet.getInt("durationminutes");
                LocalDateTime startDate = resultSet.getTimestamp("startdate").toLocalDateTime();
                int numberOfSeats = resultSet.getInt("numberofseats");
                LocalDateTime creationDate = resultSet.getTimestamp("creationdata").toLocalDateTime();


                Show show = new Show(name, durationMinutes, startDate, numberOfSeats, creationDate);
                show.setId(id);
                usersOnPage.add(show);
            }
        }
        return usersOnPage;
    }

    @Override
    public Page<Show> findAllOnPage(Pageable pageable, int flag) {
        try (Connection connection = DriverManager.getConnection(url, username, password)) {
            int totalNumberOfUsers = count(connection);
            List<Show> showsOnPage;
            if(totalNumberOfUsers > 0)
            {
                if(flag == 0){
                    showsOnPage = findAllOnPage(connection, pageable);
                } else {
                    showsOnPage = findAllOnPageReordonare(connection, pageable);
                }

            }
            else
            {
                showsOnPage = new ArrayList<>();
            }
            return new Page<>(showsOnPage, totalNumberOfUsers);
        } catch (SQLException e) {
            System.out.println(e.getMessage());
            throw new RuntimeException(e);
        }
    }

    private int count(Connection connection) throws SQLException {
        String sql = "SELECT COUNT(*) FROM showuri";
        try(PreparedStatement statement = connection.prepareStatement(sql);
            ResultSet resultSet = statement.executeQuery()) {
            if(resultSet.next()) {
                return resultSet.getInt(1);
            }
        }
        return 0;
    }

    public Optional<Show> update(Show entity) {
        int rez = -1;
        try(Connection connection = DriverManager.getConnection(url, username, password);
            PreparedStatement statement = connection.prepareStatement("UPDATE showuri SET numberofseats = ? WHERE id = ?")) {
            statement.setInt(1, entity.getNumberOfSeats()-1);
            statement.setInt(2, entity.getId());
            rez = statement.executeUpdate();
        } catch (SQLException e) {
            e.printStackTrace();
        }
        if(entity==null)
            throw new IllegalArgumentException("ENTITY CANNOT BE NULL");
        //validator.validate(entity);
        if(rez > 0){
            Show newShow = entity;
            newShow.setNumberOfSeats(entity.getNumberOfSeats()-1) ;
            return Optional.of(newShow);
        }

        return null;

    }
}
