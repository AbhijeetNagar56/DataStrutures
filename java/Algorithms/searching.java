package Algorithms;
public class searching {
    // linear search
    public static int linear(int[] arr, int t) {
        for (int i = 0; i < arr.length; i++) {
            if(arr[i] == t){
                return i;
            }
        }
        return -1;
    }

    // binary search 
    public static int binary(int[] arr, int t) {
        int l = 0;
        int r = arr.length - 1;
        while(l <= r) {
            int mid = (l + r) / 2;
            if (arr[mid] == t) {
                return mid;
            } else if (arr[mid] < t) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return -1;
    }

    

    public static void main(String[] args) {
        System.out.println();
        int arr[] = {1, 2, 3, 4, 5};
        int idx = binary(arr, 5);
        System.out.println(idx);
    }
}
