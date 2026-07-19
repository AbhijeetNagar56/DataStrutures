#include <iostream>
using namespace std;

int main() {
    int n, k, adv = 0;
    cin >> n;
    cin >> k;

    for(int i = 0; i < n; i++) {
        int score;
        cin >> score;
        if(score > k) adv++;
    }

    cout << adv << endl;
    return 0;

}