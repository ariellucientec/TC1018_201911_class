import java.util.Random;
import java.util.Arrays;

public class NaiveSearch
{
    public int[] randomArray(int numElem)
    {
        int[] arr = new int[numElem];
        Random r = new Random();
        for (int i = 0; i < numElem; i++)
        {
            arr[i] = (r.nextInt(100)+1);
        }
        Arrays.sort(arr);
        return arr;
    }
    public int secuential(int[] array, int k)
    {
        long start = System.nanoTime();
        for(int cont = 0; cont<array.length;cont++)
        {
            if(array[cont] == k)
            {
                long end = System.nanoTime();
                long duration = end-start;
                System.out.println("\nthe search took: " + duration + " nanoseconds");            
                return cont; 
            }
        }
        return -1;
    }
    public int improvedSearch(int[] array, int k)
    {
        return 0;
    }
    public void print(int[]arr)
    {
        for(int a : arr)
            System.out.print(a+ " ");
    }
    public static void main(String[] args) 
    {
        NaiveSearch b = new NaiveSearch();
        int[] arr = b.randomArray(50);
        b.print(arr);
        int foundIn = b.secuential(arr, 40);
        if(foundIn != -1)
            System.out.println("the element was found at position " + foundIn+1);
        else
            System.out.println("not found");
    }
}