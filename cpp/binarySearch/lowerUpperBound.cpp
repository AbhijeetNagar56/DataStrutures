#include <iostream>
#include <vector>
using namespace std;

int lower_bound(vector<int>& arr, int val) {
    int l = 0, h = arr.size() - 1;

    while(l < h) {
        int m = l + (h - l) / 2;
        if(arr[m] < val) {
            l = m + 1;
        } else {
            h = m;
        }
    }

    return l;
}

int upper_bound(vector<int>& arr, int val) {
    int l = 0, h = arr.size() - 1;

    while(l < h) {
        int m = l + (h - l) / 2;
        if(arr[m] <= val) {
            l = m + 1;
        } else {
            h = m;
        }
    }

    return l;
}

int main () {

    vector<int> v = {1, 2, 6, 6, 2};

    cout << "Lower bound for 6: " << to_string(lower_bound(v, 6)) << endl;
    cout << "Upper bound for 6: " << to_string(upper_bound(v, 6)) << endl;

    return 0;
}