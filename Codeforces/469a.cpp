#include <iostream>
#include <unordered_set>
using namespace std;
int main() {
    int n, p;
    cin >> n;
    cin >> p;
    unordered_set<int> Set;
    for(int i=0; i<2*p; i++) {
        int a;
        cin >> a;
        Set.insert(a);
    }
    if(Set.size() == n) {
        cout << "I become the guy.";
    } else {
        cout << "Oh, my keyboard!";
    }
    cout << endl;
    return 0;
}