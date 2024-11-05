package tests;

import decorator.DelayTaskRunner;
import decorator.PrinterTaskRunner;
import decorator.StrategyTaskRunner;
import decorator.TaskRunner;
import factory.Strategy;
import model.Container;
import model.MessageTask;

import java.util.ArrayList;

public class DelayTaskRunnerTest {
    public static void delayTaskRunnerTest(Strategy strategy, ArrayList<MessageTask> messageTasks) {
        //vis StrategyTaskRunner
        StrategyTaskRunner strategyTaskRunner = new StrategyTaskRunner(strategy);
        messageTasks.forEach(element -> {
            strategyTaskRunner.addTask(element);
        });
        strategyTaskRunner.executeOneTask();
        strategyTaskRunner.executeAll();
        strategyTaskRunner.executeOneTask();

        //via DelayTaskRunner
        StrategyTaskRunner strategyTaskRunnerWithDecorator = new StrategyTaskRunner(strategy);
        messageTasks.forEach(element ->{
            strategyTaskRunnerWithDecorator.addTask(element);
        });
        TaskRunner runner = new DelayTaskRunner(strategyTaskRunnerWithDecorator);
        runner.executeOneTask();

        //via PrinterTaskRunner
        StrategyTaskRunner strategyTaskRunnerWithDecorator2 = new StrategyTaskRunner(strategy);
        messageTasks.forEach(element ->{
            strategyTaskRunnerWithDecorator2.addTask(element);
        });
        TaskRunner runner2 = new PrinterTaskRunner(strategyTaskRunnerWithDecorator2);
        runner2.executeOneTask();


    }
}
