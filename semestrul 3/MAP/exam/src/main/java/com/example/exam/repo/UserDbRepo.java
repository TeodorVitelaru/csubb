package com.example.exam.repo;

import com.example.exam.domain.Show;
import com.example.exam.domain.User;

import java.sql.*;
import java.time.LocalDateTime;
import java.util.HashSet;
import java.util.Set;

public class UserDbRepo {
    private String url;
    private String username;
    private String password;

    public UserDbRepo(String url, String username, String password) {
        this.url = url;
        this.username = username;
        this.password = password;
    }

    public Iterable<User> findAll() {
        Set<User> users = new HashSet<>();
        try(Connection connection = DriverManager.getConnection(url, username, password);
            PreparedStatement statement = connection.prepareStatement("SELECT * from users");
            ResultSet resultSet = statement.executeQuery()) {

            while(resultSet.next())
            {
                Long id = resultSet.getLong("id");
                String email = resultSet.getString("email");
                String name = resultSet.getString("name");

                User user = new User(email, name);
                user.setId(id);
                users.add(user);

            }
            return users;
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return users;
    }

}
