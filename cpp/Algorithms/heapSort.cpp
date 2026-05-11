#include <iostream>
using namespace std;


// min heap 
void heapify(int arr[], int n, int i) {
    // left 2 * i + 1 right 2 * i + 2
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if(right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        arr[i] = arr[i] + arr[largest] - (arr[largest] = arr[i]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        arr[0] = arr[0] + arr[i] - (arr[i] = arr[0]);

        heapify(arr, i, 0);
    }
}

int main() {
    int arr[] = {2, 4, 6, 0, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, n);

    cout << "Sorted Array : ";
    for(int n: arr) {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}