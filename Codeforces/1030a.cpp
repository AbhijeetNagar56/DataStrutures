#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	bool easy = true;
	for(int i=0; i<n; i++) {
		int op;
		cin >> op;
		if(op == 1) {
			easy = false;
			break;
		}
	}

	if(easy) {
		cout << "EASY" << endl;
	} else {
		cout << "HARD" << endl;
	}
	return 0;
}