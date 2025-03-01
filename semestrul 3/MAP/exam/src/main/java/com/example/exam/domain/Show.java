package com.example.exam.domain;

import java.time.LocalDateTime;
import java.util.Objects;

public class Show {
    private int id;
    private String name;
    private int durationMinutes;
    private LocalDateTime startDate;
    private int numberOfSeats;
    private LocalDateTime creationDate;

    public Show(String name, int durationMinutes, LocalDateTime startDate, int numberOfSeats, LocalDateTime creationDate) {
        this.name = name;
        this.durationMinutes = durationMinutes;
        this.startDate = startDate;
        this.numberOfSeats = numberOfSeats;
        this.creationDate = creationDate;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getDurationMinutes() {
        return durationMinutes;
    }

    public void setDurationMinutes(int durationMinutes) {
        this.durationMinutes = durationMinutes;
    }

    public LocalDateTime getStartDate() {
        return startDate;
    }

    public void setStartDate(LocalDateTime startDate) {
        this.startDate = startDate;
    }

    public int getNumberOfSeats() {
        return numberOfSeats;
    }

    public void setNumberOfSeats(int numberOfSeats) {
        this.numberOfSeats = numberOfSeats;
    }

    public LocalDateTime getCreationDate() {
        return creationDate;
    }

    public void setCreationDate(LocalDateTime creationDate) {
        this.creationDate = creationDate;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Show show = (Show) o;
        return id == show.id;
    }

    @Override
    public int hashCode() {
        return Objects.hash(id);
    }

}
