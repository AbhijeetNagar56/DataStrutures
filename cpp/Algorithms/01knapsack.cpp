#include <iostream>
#include <vector>
using namespace std;

class item {
    int wt;
    int pf;
    item(int w, int p) {
        this->wt = w;
        this->pf = p;
    }
};


int max_profit(int n, int m, vector<item>& a) {
    
}

int main() {
    int n = 3;
    int m = 60;
    vector<item> arr(n);
    arr[0] = new item(10, 20);
    arr[1] = new item(50, 40);
    arr[2] = new item(30, 25);

    return 0;
}