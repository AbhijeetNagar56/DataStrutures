#include <iostream>
#include <iomanip>
using namespace std;
int main() {
	int n;
    double sum=0; 
	cin >> n;
    int cpy=n;
    while(n--) {
        int p;
        cin >> p;
        sum+=p;
    }
    double avg = sum / cpy;
    cout << fixed << setprecision(12) << avg << endl;
	return 0;
}