#include <iostream>
#include <vector>
using namespace std;

int main () {
	int n;
	cin >> n;
	vector<vector<int>> forces(n, vector<int>(3, 0));
	for(int i=0; i<n; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		forces[i] = { x, y, z };
	}
	vector<int> fnet(3,0);
	for(vector<int> f: forces) {
		fnet[0] += f[0];
		fnet[1] += f[1];
		fnet[2] += f[2];
	}

	if(fnet[0] == 0 && fnet[1] == 0 && fnet[2] == 0) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}

	return 0;
}