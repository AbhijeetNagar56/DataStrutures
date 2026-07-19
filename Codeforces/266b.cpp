#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
	int n, t;
	cin >> n >> t;
	string q;
	q.resize(n);
	for(int i=0; i<n; i++) {
		cin >> q[i];
	}
	while(t--) {
		for(int i=1; i<n; i++) {
			if(q[i] == 'G' && q[i-1] == 'B') {
				swap(q[i], q[i-1]);
				i++;
			}
		}
	}
	cout << q << endl;
	return 0;
}