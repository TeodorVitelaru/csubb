package factory;

import model.Container;
import model.QueueContainer;
import model.StackContainer;

public class TaskContainerFactory implements Factory{

    private TaskContainerFactory() {}


    private static TaskContainerFactory instance = new TaskContainerFactory();

    public static TaskContainerFactory getInstance() {
        return instance;
    }

    @Override
    public Container createContainer(Strategy strategy) {
        if(strategy.equals(Strategy.LIFO))
        {
            return new StackContainer();
        } else if(strategy.equals(Strategy.FIFO))
        {
            return new QueueContainer();
        }
        return null;
    }
}
