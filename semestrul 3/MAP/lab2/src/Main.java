import decorator.DelayTaskRunner;
import decorator.PrinterTaskRunner;
import decorator.StrategyTaskRunner;
import decorator.TaskRunner;
import factory.Strategy;
import model.*;
import tests.DelayTaskRunnerTest;

import java.time.LocalDateTime;
import java.util.ArrayList;

public class Main {
    public static void main(String[] args) {

        //teste sortari
        System.out.println("Test task - BUBBLESORT: [1, 4, 3]");
        SortingTask task1 = new SortingTask("1", "Hello", new int[]{1, 4, 3}, SortStrategy.BUBBLESORT);
        task1.execute();

        System.out.println("Test task - QUICKSORT: [4, 3, 2, 1]");
        SortingTask task2 = new SortingTask("2", "Hello", new int[]{4, 3, 2, 1}, SortStrategy.MERGESORT);
        task2.execute();

        MessageTask messageTask1 = new MessageTask("Salut!", "Dan", "Maria", LocalDateTime.of(2024, 10, 1, 6, 29), "1", "good job");
        MessageTask messageTask2 = new MessageTask("Bravo!", "Ion", "Ioana", LocalDateTime.of(2024, 10, 1, 7, 29), "2", "good job");
        MessageTask messageTask3 = new MessageTask("Cum mai esti?", "Ion", "Ana", LocalDateTime.of(2024, 10, 1, 8, 29), "3", "good job");
        MessageTask messageTask4 = new MessageTask("La revedere!", "Ion", "Ioana", LocalDateTime.of(2024, 10, 1, 9, 29), "4", "good job");
        MessageTask messageTask5 = new MessageTask("Salut!", "Dan", "Maria", LocalDateTime.of(2024, 10, 1, 10, 29), "5", "good job");
        ArrayList<MessageTask> listOfMesssages = new ArrayList<>();
        listOfMesssages.add(messageTask1);
        listOfMesssages.add(messageTask2);
        listOfMesssages.add(messageTask3);
        listOfMesssages.add(messageTask4);
        listOfMesssages.add(messageTask5);

        for (MessageTask message : listOfMesssages) {
            System.out.println(message.toString());
        }

        // Scrieți un program de test care creeaza un vector de task-ri de tipul
        // MessageTask si le executa, via un obiect de tipul StrategyTaskRunner,
        // folosind strategia specificata ca parametru in linia de comanda. (main(String[] args).

        // Execution via Strategy Task Runner
        StrategyTaskRunner strategyTaskRunner = new StrategyTaskRunner(Strategy.valueOf(args[0]));
        listOfMesssages.forEach(element -> {
            strategyTaskRunner.addTask(element);
        });
        strategyTaskRunner.executeOneTask();
        strategyTaskRunner.executeAll();
        strategyTaskRunner.executeOneTask();

        // Execution via Decorator
        StrategyTaskRunner strategyTaskRunnerWithDecorator = new StrategyTaskRunner(Strategy.valueOf(args[0]));
        listOfMesssages.forEach(element ->{
            strategyTaskRunnerWithDecorator.addTask(element);
        });
        TaskRunner runner = new PrinterTaskRunner(strategyTaskRunnerWithDecorator);
        runner.executeOneTask();

        System.out.println("\nPentru Lab:");
        //Via StrategyTaskRunner, DelayTaskRunner, PrinterTaskRunner
        DelayTaskRunnerTest.delayTaskRunnerTest(Strategy.valueOf(args[0]), listOfMesssages);
    }
}