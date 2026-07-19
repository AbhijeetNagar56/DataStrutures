#include <iostream>
using namespace std;

int main() {
    int n, total = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int v, curr;
        for(int j = 0; j < 3; j++) {
            cin >> v;
            curr += v;
        }
        if(curr >= 2) {
            total++;
        }
        curr = 0;
    }
    
    cout << total << endl;

    return 0;
}
