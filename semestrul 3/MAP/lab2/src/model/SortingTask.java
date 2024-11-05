package model;

import java.util.ArrayList;
import java.util.Arrays;

public class SortingTask extends Task{

    private AbstractSorter abstractSorter;
    private int[] numere;
    private SortStrategy sortStrategy;

    public SortingTask(String taskId, String description, int[] numere, SortStrategy sortStrategy) {
        super(taskId, description);
        this.numere = numere;
        this.sortStrategy = sortStrategy;
        if(sortStrategy.equals(SortStrategy.BUBBLESORT))
        {
            abstractSorter = new BubbleSort();
        } else if(sortStrategy.equals(SortStrategy.MERGESORT))
        {
            abstractSorter = new QuickSort();
        }
    }

    @Override
    public void execute() {
        abstractSorter.sort(numere);
        System.out.println(Arrays.toString(numere) + '\n');
    }
}
