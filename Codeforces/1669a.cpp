#include <iostream>
using namespace std;

int division(int rating) {
    if(rating >= 1900) {
        return 1;
    } else if(rating >= 1600) {
        return 2;
    } else if(rating >= 1400) {
        return 3;
    } else {
        return 4;
    }
}

void helper() {
    int rating;
    cin >> rating;
    cout << "Division " << division(rating) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        helper();
    }
    
    return 0;
}