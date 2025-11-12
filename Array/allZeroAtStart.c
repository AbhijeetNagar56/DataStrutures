#include<stdio.h>


int main () {
    int arr[8] = {1, 0, 2, 0, 3, 0, 4, 5};
    int l = 0;
    int r = 0;
    
    while(r < sizeof(arr)/sizeof(int)) {
        if(arr[r] == 0) {
            int temp = arr[l];
            arr[l] = arr[r];
            arr[r] = temp;
            l++;
            r++;
        } else {
            r++;
        }
    }

    for (int i = 0; i < sizeof(arr)/sizeof(int); i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}