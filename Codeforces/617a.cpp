#include <iostream>
using namespace std;

int main() {
	int dist;
	cin >> dist;
	int step;
	while(dist > 0) {
		step++;
		dist -= 5;
	}
	cout << step << endl;
	return 0;
}