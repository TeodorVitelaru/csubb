package com.example.exam.domain;

public class User {
    private Long id;
    private String email;
    private String name;
    private Boolean notificaion = true;
    private Boolean reservedSeat = false;

    public User(String email, String name) {
        this.email = email;
        this.name = name;
    }

    public Long getId() {
        return id;
    }

    public void setId(Long id) {
        this.id = id;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public void setNotificaion(Boolean adev){
        this.notificaion = adev;
    }

    public Boolean getNotificaion(){
        return this.notificaion;
    }

    public void setReservedSeat(Boolean reservedSeat) {
        this.reservedSeat = reservedSeat;
    }

    public Boolean getReservedSeat(){
        return this.reservedSeat;
    }
}
