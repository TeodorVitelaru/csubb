package com.example.exam.service;

import com.example.exam.domain.Page;
import com.example.exam.domain.Pageable;
import com.example.exam.domain.Show;
import com.example.exam.domain.User;
import com.example.exam.repo.ShowDbRepo;
import com.example.exam.repo.UserDbRepo;
import com.example.exam.utils.events.ChangeEventType;
import com.example.exam.utils.events.EntityChangeEvent;
import com.example.exam.utils.observer.Observable;
import com.example.exam.utils.observer.Observer;

import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import java.util.List;
import java.util.Optional;

public class ServiceShow  implements Observable<EntityChangeEvent> {
    private ShowDbRepo showDbRepo;
    private UserDbRepo userDbRepo;
    private List<Observer<EntityChangeEvent>> observers = new ArrayList<>();


    public ServiceShow(ShowDbRepo showDbRepo, UserDbRepo userDbRepo) {
        this.showDbRepo = showDbRepo;
        this.userDbRepo = userDbRepo;
    }

    public Iterable<Show> getAllShows() {
        try{
            return showDbRepo.findAll();
        } catch (Exception e) {
            return null;
        }
    }

    public Iterable<User> getAllUsers() {
        try{
            return userDbRepo.findAll();
        } catch (Exception e) {
            return null;
        }
    }

    public Page<Show> getShowsOnPage(Pageable pageable, int flag) {
        try {
            return this.showDbRepo.findAllOnPage(pageable, flag);
        } catch (Exception e) {
            return null;
        }
    }

    public void reserveSeat(Show show){
        Show newShow = showDbRepo.update(show).get();
        EntityChangeEvent<Show> event = new EntityChangeEvent<>(ChangeEventType.UPDATE, show, newShow);
        notifyObservers(event);
    }


    public Optional<Show> addShow(String name, int durationMinutes, String startDate, int numberOfSeats) {
        try {
            DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm");
            LocalDateTime newStartDate = LocalDateTime.parse(startDate, formatter);
            LocalDateTime newEndDate = newStartDate.plusMinutes(durationMinutes);

            Iterable<Show> shows = showDbRepo.findAll();
            for (Show show : shows) {
                LocalDateTime existingStartDate = show.getStartDate();
                LocalDateTime existingEndDate = existingStartDate.plusMinutes(show.getDurationMinutes());

                if (!((newStartDate.isBefore(existingStartDate) && newEndDate.isBefore(existingStartDate)) || (newStartDate.isAfter(existingEndDate) && newEndDate.isAfter(existingEndDate)))) {
                    throw new Exception("Show overlaps with existing show");
                }
            }

            Show newShow = new Show(name, durationMinutes, newStartDate, numberOfSeats, LocalDateTime.now());
            Optional<Show> show = showDbRepo.save(newShow);
            if(show.isPresent()) {
                EntityChangeEvent event = new EntityChangeEvent(ChangeEventType.ADD, newShow);
                notifyObservers(event);
                return show;
            }

        } catch (Exception e) {
            return Optional.empty();
        }

        return Optional.empty();
    }

    @Override
    public void addObserver(Observer<EntityChangeEvent> e) {
        observers.add(e);
    }

    @Override
    public void removeObserver(Observer<EntityChangeEvent> e) {
        observers.remove(e);
    }

    @Override
    public void notifyObservers(EntityChangeEvent t) {
        observers.forEach(x -> x.update(t));
    }
}
