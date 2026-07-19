#include <iostream>
using namespace std;

int main() {
	int stops;
	cin >> stops;
	int curr = 0;
	int peak = 0;
	while(stops--) {
		int in, out;
		cin >> out >> in;
		curr = curr - out + in;
		peak = max(peak, curr);
	}
	cout << peak << endl;
	return 0;
}
