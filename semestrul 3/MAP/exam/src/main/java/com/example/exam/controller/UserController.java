package com.example.exam.controller;

import com.example.exam.domain.Page;
import com.example.exam.domain.Pageable;
import com.example.exam.domain.Show;
import com.example.exam.domain.User;
import com.example.exam.service.ServiceShow;
import com.example.exam.utils.events.ChangeEventType;
import com.example.exam.utils.events.EntityChangeEvent;
import com.example.exam.utils.observer.Observer;
import javafx.beans.property.SimpleLongProperty;
import javafx.beans.property.SimpleStringProperty;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.*;

import java.security.cert.TrustAnchor;

public class UserController implements Observer<EntityChangeEvent> {
    private ServiceShow service;
    private User loggedInUser;
    private int currentPage = 0;
    private int PAGE_SIZE = 3;
    private ObservableList<Show> model = FXCollections.observableArrayList();
    private Boolean reordonare = false;

    @FXML
    private TableView<Show> tableViewShows;
    @FXML
    private TableColumn<Show, Long> tableColumnShowId;
    @FXML
    private TableColumn<Show, String> tableColumnName;
    @FXML
    private TableColumn<Show, Long> tableColumnDurationMinutes;
    @FXML
    private TableColumn<Show, Long> tableColumnNumberOfSeats;
    @FXML
    private TableColumn<Show, String>  tableColumnStartDate;
    @FXML
    private TableColumn<Show, String>  tableColumnCreationDate;
    @FXML
    private TableColumn<Show, Void> tableColumnReserve;


    @FXML
    private Button buttonPrev;
    @FXML
    private Button buttonNext;


    public void setService(ServiceShow service, User loggedInUser) {
        this.service = service;
        this.loggedInUser = loggedInUser;
        service.addObserver(this);
        initModel();
    }

    public void initModel() {
        loadPage(currentPage);
        intialize();
    }

    private void intialize() {
        tableColumnShowId.setCellValueFactory(cellData -> new SimpleLongProperty(cellData.getValue().getId()).asObject());
        tableColumnName.setCellValueFactory(cellData -> new SimpleStringProperty(cellData.getValue().getName()));
        tableColumnDurationMinutes.setCellValueFactory(cellData -> new SimpleLongProperty(cellData.getValue().getDurationMinutes()).asObject());
        tableColumnNumberOfSeats.setCellValueFactory(cellData -> new SimpleLongProperty(cellData.getValue().getNumberOfSeats()).asObject());
        tableColumnStartDate.setCellValueFactory(cellData -> new SimpleStringProperty(cellData.getValue().getStartDate().toString()));
        tableColumnCreationDate.setCellValueFactory(cellData -> new SimpleStringProperty(cellData.getValue().getCreationDate().toString()));
        addButtonToTable();
        tableViewShows.setItems(model);
    }

    private void addButtonToTable() {
        tableColumnReserve.setCellFactory(param -> new TableCell<Show, Void>() {
            private final Button btn = new Button("Reserve");

            {
                btn.setOnAction(event -> {
                    Show show = getTableView().getItems().get(getIndex());
                    handleReserve(show);
                });
            }

            @Override
            protected void updateItem(Void item, boolean empty) {
                super.updateItem(item, empty);
                if (empty) {
                    setGraphic(null);
                } else {
                    Show show = getTableView().getItems().get(getIndex());
                    btn.setDisable(show.getNumberOfSeats() <= 0 || loggedInUser.getReservedSeat());
                    setGraphic(btn);
                }
            }
        });
    }

    public void handleReserve(Show show){
        service.reserveSeat(show);
        loggedInUser.setReservedSeat(true);
    }

    private void loadPage(int page) {
        Pageable pageable = new Pageable(PAGE_SIZE, page);
        Page<Show> showsOnPage = null;
        if(reordonare == false){
            showsOnPage = service.getShowsOnPage(pageable, 0);
        } else{
            showsOnPage = service.getShowsOnPage(pageable, 1);
        }

        buttonPrev.setDisable(page == 0);
        model.clear();
        model.setAll(showsOnPage.getContent());
    }


    public void handlePrevious(ActionEvent actionEvent) {
        if(currentPage > 0) {
            currentPage--;
            buttonPrev.setDisable(currentPage == 0);
            buttonNext.setDisable(false);
            loadPage(currentPage);
        }
    }

    public void handleNext(ActionEvent actionEvent) {
        if(reordonare == false){
            if(currentPage < service.getShowsOnPage(new Pageable(PAGE_SIZE, currentPage), 0).getTotalElements() / PAGE_SIZE)
            {
                currentPage++;
                buttonPrev.setDisable(false);
                buttonNext.setDisable(currentPage == service.getShowsOnPage(new Pageable(PAGE_SIZE, currentPage), 1).getTotalElements() / PAGE_SIZE);
                loadPage(currentPage);
            }
        } else{
            if(currentPage < service.getShowsOnPage(new Pageable(PAGE_SIZE, currentPage), 1).getTotalElements() / PAGE_SIZE)
            {
                currentPage++;
                buttonPrev.setDisable(false);
                buttonNext.setDisable(currentPage == service.getShowsOnPage(new Pageable(PAGE_SIZE, currentPage), 1).getTotalElements() / PAGE_SIZE);
                loadPage(currentPage);
            }
        }

    }

    @Override
    public void update(EntityChangeEvent entityChangeEvent) {
        if(entityChangeEvent.getType().equals(ChangeEventType.ADD))
        {
            if(entityChangeEvent.getData() instanceof Show)
            {
                Alert alert = new Alert(Alert.AlertType.CONFIRMATION, "Show added. Do you want to view the shows?", ButtonType.YES, ButtonType.NO);
                if(loggedInUser.getNotificaion() == true){
                    alert.showAndWait().ifPresent(response -> {
                        loggedInUser.setNotificaion(false);
                        if (response == ButtonType.YES) {
                            // Logic to display the shows
                            System.out.println("Displaying shows...");
                            Show show = (Show) entityChangeEvent.getData();
                            model.add(show);
                            reordonare = true;
                            loadPage(currentPage);
                            loggedInUser.setNotificaion(true);
                        } else if(response == ButtonType.NO){
                            loggedInUser.setNotificaion(false);
                        }
                    });
                }
            }
        }
        if(entityChangeEvent.getType().equals(ChangeEventType.UPDATE)){
            if(entityChangeEvent.getData() instanceof Show){
                Show show = (Show) entityChangeEvent.getOldData();
                Show newShow = (Show) entityChangeEvent.getData();
                int index = model.indexOf(show);
                if (index != -1) {
                    model.set(index, newShow);
                    System.out.println("aici");
                }

            }
        }
    }
}
