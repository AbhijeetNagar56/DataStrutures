#include <iostream>
using namespace std;


int linear(int arr[], int n, int key) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int binary(int arr[], int low, int high, int key) {
    if(low >= high) {
        return -1;
    } 

    mid = low + ( mid - low ) / 2
    if(arr[mid] == key) {
        return mid;
    } else if(arr[mid] < key) {
        return binary(arr, mid, high, key);
    } else {
        return binary(arr, low, mid, key);
    }
    

}

int main () {

    return 0;
}