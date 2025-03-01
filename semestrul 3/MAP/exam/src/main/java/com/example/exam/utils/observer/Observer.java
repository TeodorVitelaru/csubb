package com.example.exam.utils.observer;

import com.example.exam.utils.events.Event;

public interface Observer <E extends Event>{
    void update(E e);
}