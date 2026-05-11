#include <iostream>
using namespace std;

void merge(int arr[], int l, int mid, int h) {
    int n1 = mid - l + 1;
    int n2 = h - mid;

    int* leftArray = new int[n1];
    int* rightArray = new int[n2];

    for(int i = 0; i < n1; i++) {
        leftArray[i] = arr[l + i];
    }

    for(int j = 0; j < n2; j++) {
        rightArray[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = l;

    while(i < n1 && j < n2) {
        if(leftArray[i] < rightArray[j]) {
            arr[k] = leftArray[i];
            i++;
        } else {
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while(i < n1) {
        arr[k] = leftArray[i];
        i++;
        k++;
    }

    while(j < n2) {
        arr[k] = rightArray[j];
        j++;
        k++;
    }

    delete[] leftArray;
    delete[] rightArray;

}

void mergeSort(int arr[], int l, int h) {
    if(l < h) {
        int mid = l + (h - l) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, h);
        merge(arr, l, mid, h);
    }
}


int main() {
    int a[] = {2, 1, 0, 4, 6};
    int n = sizeof(a) / sizeof(a[0]);

    mergeSort(a, 0, n - 1);

    cout << "Sorted array : ";
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
    
    return 0;
}