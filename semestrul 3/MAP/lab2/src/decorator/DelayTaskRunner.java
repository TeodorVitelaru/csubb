package decorator;

public class DelayTaskRunner extends AbstractTaskRunner {

    public DelayTaskRunner(TaskRunner runner) {
        super(runner);
    }

    @Override
    public void executeOneTask()
    {
        super.executeOneTask();
        try{
            Thread.sleep(3000);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
}
