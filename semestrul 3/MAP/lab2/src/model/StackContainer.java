package model;

import java.util.ArrayList;

public class StackContainer extends AbstractContainer {

    public StackContainer() {
        this.tasks = new ArrayList<>();
    }

    @Override
    public Task remove() {
        if(isEmpty())
            return null;
        else {
            return tasks.remove(tasks.size()-1);
        }
    }

}

