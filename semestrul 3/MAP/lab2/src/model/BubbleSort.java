package model;

public class BubbleSort extends AbstractSorter{

    @Override
    public void sort(int[] numere)
    {
        int n = numere.length;
        for(int i = 0; i < n; i++)
        {
            for(int j=0; j<n-1; j++)
            {
                if(numere[j] > numere[j+1])
                {
                    int temp = numere[j];
                    numere[j] = numere[j+1];
                    numere[j+1] = temp;
                }
            }
        }
    }
}
