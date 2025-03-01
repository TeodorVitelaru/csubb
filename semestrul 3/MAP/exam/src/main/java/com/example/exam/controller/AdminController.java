package com.example.exam.controller;

import com.example.exam.domain.Show;
import com.example.exam.service.ServiceShow;
import com.example.exam.utils.events.ChangeEventType;
import com.example.exam.utils.events.EntityChangeEvent;
import com.example.exam.utils.observer.Observer;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Alert;
import javafx.scene.control.TextField;

import java.util.Optional;

public class AdminController implements Observer<EntityChangeEvent> {
    private ServiceShow service;

    @FXML
    private TextField nameField;
    @FXML
    private TextField durationMinutesField;
    @FXML
    private TextField startDateField;
    @FXML
    private TextField numberOfSeatsField;

    public void setService(ServiceShow service) {
        this.service = service;
        service.addObserver(this);

    }


    public void handleAdd(ActionEvent actionEvent) {
        try{
            String name = nameField.getText();
            int durationMinutes = Integer.parseInt(durationMinutesField.getText());
            String startDate = startDateField.getText();
            int numberOfSeats = Integer.parseInt(numberOfSeatsField.getText());
            Optional<Show> show = service.addShow(name, durationMinutes, startDate, numberOfSeats);
            if(show.isPresent()){
                System.out.println("Show added");
            } else {
                Alert alert = new Alert(Alert.AlertType.WARNING, "There are other shows starting at this time.");
                alert.showAndWait();
            }
            nameField.clear();
            durationMinutesField.clear();
            startDateField.clear();
            numberOfSeatsField.clear();
        } catch (RuntimeException rex) {
            System.out.println("Error adding show " + rex);
        }
    }

    @Override
    public void update(EntityChangeEvent entityChangeEvent) {
        if(entityChangeEvent.getType().equals(ChangeEventType.ADD))
        {

        }
    }
}
