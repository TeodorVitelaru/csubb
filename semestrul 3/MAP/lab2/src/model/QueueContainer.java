package model;

import java.util.ArrayList;

public class QueueContainer extends AbstractContainer {

    public QueueContainer() {
        this.tasks = new ArrayList<>();
    }

    @Override
    public Task remove()
    {
        if(isEmpty())
        {
            return null;
        } else {
            return this.tasks.remove(0);
        }
    }
}
