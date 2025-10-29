package Algorithms;
import java.util.*;

public class sortingAdv {
    public static void bucketSort(int[] arr) {
        if (arr.length == 0)
            return;

        int max = arr[0];
        for (int num : arr) {
            if (num > max) {
                max = num;
            }
        }

        int numberOfBuckets = (int) Math.sqrt(arr.length); 
        List<List<Integer>> buckets = new ArrayList<>(numberOfBuckets);
        for (int i = 0; i < numberOfBuckets; i++) {
            buckets.add(new ArrayList<>());
        }

        for (int num : arr) {
            int bucketIndex = (num * numberOfBuckets) / (max + 1);
            buckets.get(bucketIndex).add(num);
        }

        for (List<Integer> bucket : buckets) {
            Collections.sort(bucket); 
        }

        int index = 0;
        for (List<Integer> bucket : buckets) {
            for (int num : bucket) {
                arr[index++] = num;
            }
        }
    }

    public static void main(String[] args) {
        System.out.println();
        int[] arr = { 170, 45, 75, 90, 802, 24, 2, 66 };

        System.out.println("Original Array:");
        for (int num : arr) {
            System.out.print(num + " ");
        }

        bucketSort(arr);

        System.out.println("\nSorted Array:");
        for (int num : arr) {
            System.out.print(num + " ");
        }

        int[] Array = new int[20];
        Random random = new Random();

        for (int i = 0; i < Array.length; i++) {
            Array[i] = random.nextInt(100);
        }

        // time for low input
        long st1 = System.nanoTime();
        bucketSort(Array);
        long et1 = System.nanoTime();
        long t1 = (et1 - st1) / 1000;
        System.out.println("The time for low input size : " + t1 + " mircro second.");

        int[] Array1 = new int[2000];

        for (int i = 0; i < Array1.length; i++) {
            Array1[i] = random.nextInt(1000);
        }

        // time for medium input
        long st2 = System.nanoTime();
        bucketSort(Array1);
        long et2 = System.nanoTime();
        long t2 = (et2 - st2) / 1000;
        System.out.println("The time for medium input size : " + t2 + " micro second.");

        int[] Array2 = new int[200000];

        for (int i = 0; i < Array2.length; i++) {
            Array2[i] = random.nextInt(10000);
        }

        // time for large input
        long st3 = System.nanoTime();
        bucketSort(Array2);
        long et3 = System.nanoTime();
        long t3 = (et3 - st3) / 1000;
        System.out.println("The time in large input size : " + t3 + " micro second.");

    }
}
