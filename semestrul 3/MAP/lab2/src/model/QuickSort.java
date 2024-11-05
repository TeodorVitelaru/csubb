package model;

public class QuickSort extends AbstractSorter {

    @Override
    public void sort(int[] numere)
    {
        quickSort(numere, 0, numere.length-1);
    }

    public void quickSort(int[] numere, int left, int right)
    {
        if(left < right)
        {
            int partitionAux = partition(numere, left, right);
            quickSort(numere, left, partitionAux-1);
            quickSort(numere, partitionAux+1, right);
        }
    }

    public int partition(int[] numere, int left, int right)
    {
        int pivot = numere[right];
        int i = left - 1;
        for(int j = left; j < right; j++)
        {
            if (numere[j] <= pivot)
            {
                i++;
                int temp = numere[i];
                numere[i] = numere[j];
                numere[j] = temp;
            }
        }
        int temp = numere[i+1];
        numere[i+1] = numere[right];
        numere[right] = temp;
        return i+1;
    }

}
