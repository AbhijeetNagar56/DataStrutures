#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> pos(n);
    int Max = 0;
    int Min = 0;

    for(int i=0; i<n; i++) {
        cin >> pos[i];
    }

    for(int i=0; i<n; i++) {
        if(pos[Max] < pos[i]) {
            Max = i;
        }

        if(pos[Min] >= pos[i]) {
            Min = i;
        }
    }
    int time = Min < Max ? -1 : 0;
    time += Max-0 + n - 1 - Min; 
    cout << time << endl;
    return 0;
}