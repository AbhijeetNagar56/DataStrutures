#include <iostream>
using namespace std;
int main() {
	int t;
    cin >> t;
    while(t--) {
        int a, b;
        cin >> a >> b;
        if(a%b==0) {
            cout << "0" << endl;
            continue;
        }
        int next= b*((a+b)/b) - a;
        cout << next << endl;
    }
	return 0;
}