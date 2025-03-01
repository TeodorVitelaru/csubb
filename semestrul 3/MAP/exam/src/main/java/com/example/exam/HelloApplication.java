package com.example.exam;

import com.example.exam.controller.AdminController;
import com.example.exam.controller.UserController;
import com.example.exam.domain.Show;
import com.example.exam.domain.User;
import com.example.exam.repo.ShowDbRepo;
import com.example.exam.repo.UserDbRepo;
import com.example.exam.service.ServiceShow;
import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.layout.AnchorPane;
import javafx.scene.layout.GridPane;
import javafx.stage.Stage;

import java.io.IOException;

public class HelloApplication extends Application {

    ServiceShow service;

    @Override
    public void start(Stage stage) throws IOException {
        String url = "jdbc:postgresql://localhost:5432/exam";
        String username = "postgres";
        String password = "postgres";

        ShowDbRepo repoShow = new ShowDbRepo(url, username, password);
        UserDbRepo repoUser = new UserDbRepo(url, username, password);
        this.service = new ServiceShow(repoShow, repoUser);
        initView(stage);
        stage.setWidth(800);
        stage.show();

        Iterable<User> users = service.getAllUsers();
        for (User user : users) {
            Stage stage1 = new Stage();
            initViewUser(stage1, user);
            stage1.setWidth(800);
            stage1.show();
        }
    }

    private void initViewUser(Stage stage1, User user) throws IOException{
        FXMLLoader fxmlLoader = new FXMLLoader(getClass().getResource("UserView.fxml"));

        AnchorPane loginLayout = fxmlLoader.load();
        stage1.setScene(new Scene(loginLayout));

        UserController utilizatorController = fxmlLoader.getController();
        utilizatorController.setService(this.service, user);
    }

    private void initView(Stage stage) throws IOException {
        FXMLLoader fxmlLoader = new FXMLLoader(getClass().getResource("AdmiView.fxml"));

        AnchorPane loginLayout = fxmlLoader.load();
        stage.setScene(new Scene(loginLayout));

        AdminController utilizatorController = fxmlLoader.getController();
        utilizatorController.setService(this.service);
    }

    public static void main(String[] args) {
        launch();
    }
}