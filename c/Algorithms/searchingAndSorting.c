#include <stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// bubble sort
void bsort(int arr[], int size){
    
    for(int i = 0; i < size-1; i++){
        for(int j = 0; j < size-1-i; j++){
            if(arr[j] > arr[j+1]){
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

void isort(int arr[], int size){
    for(int i = 0; i < size; i++){
        int key = arr[i];
        int j = i - 1;
        while(j>=0 && key < arr[j]){
            arr[j+1] = arr[j];
            j = j - 1;
        }
        arr[j+1] = key;
    }
}
// selection sort
void ssort(int arr[], int size){
    for(int i = 0; i < size; i++){
        int min = i;
        for(int j = i+1; j < size; j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        swap(&arr[i], &arr[min]);
    }
}


// merge sort
void merge(int arr[], int l, int mid, int h){
    int n2 = h - mid;
    int n1 = mid - l + 1;
    int larr[n1], rarr[n2];
    for(int i=0; i<n1; i++){
        larr[i] = arr[l+i];
    }
    for(int j=0; j<n2; j++){
        rarr[j] = arr[mid+1+j];
    }
    int i = 0, j = 0, k = l;
    while(i < n1 && j < n2){
        if(larr[i] < rarr[j]){
            arr[k] = larr[i];
            i++;
        } else {
            arr[k] = rarr[j];
            j++;
        }
        k++;
    }
    while(i < n1){
        arr[k] = larr[i];
        i++;
        k++;
    }
    while(j < n2){
        arr[k] = rarr[j];
        j++;
        k++;
    }
}
void msort(int arr[], int l, int h){
    if(l < h) {
        int mid = (l + h) / 2;
        msort(arr, l, mid);
        msort(arr, mid + 1, h);
        merge(arr, l, mid, h);
    }
}

// quick sort
int partition(int arr[], int l, int h){
    int pivot = arr[h];
    int i = l - 1;
    for(int j = l; j < h; j++){
        if(arr[j] < pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    i++;
    swap(&arr[i], &arr[h]);
    return i;
}
void qsort(int arr[], int l, int h){
    if(l < h){
        int idx = partition(arr, l, h);
        qsort(arr, l, idx-1);
        qsort(arr, idx+1, h);
    }
}

// linear search
int lsearch(int arr[], int size, int target){
    for(int i = 0; i < size; i++){
        if(arr[i]==target){
            return i;
        }
    }
    return -1;
}

// binary search
int bsearch(int arr[], int l, int h, int target){
    if(l < h){
        int mid = (l + h) / 2;
        if(arr[mid] > target){
            return bsearch(arr, l, mid-1, target);
        } else if(arr[mid] < target){
            return bsearch(arr, mid+1, h, target);
        } else {
            return mid; 
        }
    }
}

int main () {
    int a[5] = {2,0,5,3,1};
    int size = sizeof(a)/sizeof(int);
    qsort(a, 0, size-1);

    int index = lsearch(a, size, 2);

    printf("element at %d ", index);
    return 0;
}

