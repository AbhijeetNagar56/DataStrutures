package Algorithms;

public class majorityElement {
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
        int arr[] = {2, 2, 1, 1, 2, 2, 2};
        int n = arr.length;
        quickSort(arr, 0, n-1);
        System.out.println();
        int pt = 1;
        int count = 1;
        int key = arr[0];
        while(pt < n){
            if(arr[pt] != key) {
                count = 0;
                key = arr[pt];
            }
            count++;
            if(count > n / 2) break;
            pt++;
        }
        System.out.println("Majority element is " + key);
    }
}



// public class assignment3 {
//     public static double findMedianSortedArrays(int[] A, int[] B) {
//         if (A.length > B.length) { // Ensure A is the smaller array
//             return findMedianSortedArrays(B, A);
//         }

//         int m = A.length;
//         int n = B.length;
//         int totalLeft = (m + n + 1) / 2;
//         int left = 0, right = m;

//         while (left <= right) {
//             int i = (left + right) / 2;
//             int j = totalLeft - i;

//             int Aleft = (i == 0) ? Integer.MIN_VALUE : A[i - 1];
//             int Aright = (i == m) ? Integer.MAX_VALUE : A[i];
//             int Bleft = (j == 0) ? Integer.MIN_VALUE : B[j - 1];
//             int Bright = (j == n) ? Integer.MAX_VALUE : B[j];

//             if (Aleft <= Bright && Bleft <= Aright) {
//                 if ((m + n) % 2 == 0) {
//                     return (Math.max(Aleft, Bleft) + Math.min(Aright, Bright)) / 2.0;
//                 } else {
//                     return Math.max(Aleft, Bleft);
//                 }
//             } else if (Aleft > Bright) {
//                 right = i - 1; // Move partition left
//             } else {
//                 left = i + 1;  // Move partition right
//             }
//         }
//         throw new IllegalArgumentException("Input arrays are not sorted properly.");
//     }

//     public static void main(String[] args) {
//         System.out.println();
//         int[] A = {1, 3, 8};
//         int[] B = {7, 9, 10, 11};
//         System.out.println("Median = " + findMedianSortedArrays(A, B));
        
        
//     }
// }


