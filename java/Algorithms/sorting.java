package Algorithms;
import java.util.Random;

public class sorting {
    // bubble sort
    public static void bubbleSort(int[] arr) {
        for (int i = 0; i < arr.length - 1; i++) {
            for (int j = 0; j < arr.length - i - 1; j++) {
                if(arr[j] > arr[j+1]) {
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                }
            }
        }
    }

    // selection sort
    public static void selectionSort(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            int min = i;
            for (int j = i; j < arr.length; j++) {
                if(arr[min] > arr[j]) {
                    min = j;
                }
            }
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }

    // insertion sort
    public static void insertionSort(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && key < arr[j]) {
                arr[j+1] = arr[j];
                j--;
            }
            arr[j+1] = key;
        }
    }

    // merge sort
    public static void mergeSort(int[] arr, int low, int high) {
        if (low < high) {
            int mid = (high+low) / 2;
            mergeSort(arr, low, mid);
            mergeSort(arr, mid + 1, high);
            merge(arr, low, mid, high);
        }
    }
    public static void merge(int[] arr, int low, int mid, int high) {
        int n1 = mid - low + 1;
        int n2 = high - mid;

        int[] left = new int[n1];
        int[] right = new int[n2];

        for (int i = 0; i < n1; i++) {
            left[i] = arr[low + i];
        }
        for (int j = 0; j < n2; j++) {
            right[j] = arr[mid + 1 + j];
        }

        int i = 0, j = 0, k = low;

        while (i < n1 && j < n2) {
            if (left[i] <= right[j]) {
                arr[k] = left[i];
                i++;
            } else {
                arr[k] = right[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            arr[k] = left[i];
            i++;
            k++;
        }

        while (j < n2) {
            arr[k] = right[j];
            j++;
            k++;
        }
    }


    // quick sort

    public static void quickSort(int[] arr, int low, int high) {
        if (low < high) {
            int pi = pivot(arr, low, high);

            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }
    
    public static int pivot(int[] arr, int low, int high) {
        int pe = arr[high];
        int i = low - 1;
        for(int j = low; j < high; j++) {
            if(arr[j] < pe){
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        i++;
        int temp = arr[i];
        arr[i] = arr[high];
        arr[high] = temp;

        return i;
    }

   

    public static void main(String[] args) {
        System.out.println();
        int[] Array = new int[100000];
        Random random = new Random();

        for(int i = 0; i < Array.length; i++) {
            Array[i] = random.nextInt(100);
        }

        // time for bubble sort
        long st1 = System.nanoTime();
        bubbleSort(Array);
        long et1 = System.nanoTime();
        long t1 = (et1 -st1)/1000000;
        System.out.println("The time in bubble sort is : "+ t1 + " ms.");
        
        // time for selection sort
        long st2 = System.nanoTime();
        selectionSort(Array);
        long et2 = System.nanoTime();
        long t2 = (et2 -st2)/1000000;
        System.out.println("The time in selection sort is : "+ t2 + " ms.");

        // time for insertion sort
        long st3 = System.nanoTime();
        insertionSort(Array);
        long et3 = System.nanoTime();
        long t3 = (et3 -st3)/1000000;
        System.out.println("The time in insertion sort is : "+ t3 + " ms.");

        // time for merge sort
        long st4 = System.nanoTime();
        mergeSort(Array, 0, Array.length - 1);
        long et4 = System.nanoTime();
        long t4 = (et4 -st4)/1000000;
        System.out.println("The time in merge sort is : "+ t4 + " ms.");

        // time for bubble sort
        long st5 = System.nanoTime();
        quickSort(Array, 0, Array.length - 1);
        long et5 = System.nanoTime();
        long t5= (et5 -st5)/1000000;
        System.out.println("The time in quick sort is : "+ t5 + " ms.");
    }
}
 