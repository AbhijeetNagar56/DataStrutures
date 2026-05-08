#include <iostream>
#include <vector>
#include <algorithm>

void sort012(std::vector<int>& arr) {
    int low = 0;
    int mid = 0;
    int high = arr.size() - 1;

    while (mid <= high) {
        switch (arr[mid]) {
            case 0:
                // Found a 0: swap to the 'low' section
                std::swap(arr[low++], arr[mid++]);
                break;
            case 1:
                // Found a 1: it's in the right place for now
                mid++;
                break;
            case 2:
                // Found a 2: swap to the 'high' section
                // Don't increment mid yet, we need to check the swapped element
                std::swap(arr[mid], arr[high--]);
                break;
        }
    }
}