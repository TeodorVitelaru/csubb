package model;

import java.util.ArrayList;

public abstract class AbstractContainer implements Container {
    protected ArrayList<Task> tasks = new ArrayList<>();

    public void add(Task task) {
        tasks.add(task);
    }

    public int size()
    {
        return tasks.size();
    }

    public boolean isEmpty()
    {
        return tasks.isEmpty();
    }
}
