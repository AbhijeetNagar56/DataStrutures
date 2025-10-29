#include <stdio.h>


int main () {
    int a[3] = {2,1,3};
    int n = sizeof(a)/sizeof(int);
    printf("Before Sorting : ");
    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    for(int i = 0; i < n; i++){
        int min = i;
        for(int j = i+1; j < n; j++){
            if(a[j] < a[min]){
                min = j;
            }
        }
        int temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
    printf("\nAfter Sorting : ");
    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    return 0;
}