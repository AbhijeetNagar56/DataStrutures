#include <iostream>
#include <vector>
using namespace std;

bool isNearlyLucky(long int n) {
	bool isLucky = true;
	int noOfLuckyDigits = 0;
	while(n) {
		long int digit = n % 10;
		if(digit != 4 && digit != 7) {
			isLucky = false;
		} else {
			noOfLuckyDigits++;
		}
		n /= 10;
	}

	bool nearlyLucky = true;
	while(noOfLuckyDigits) {
		long int digit = noOfLuckyDigits % 10;
		if(digit != 4 && digit != 7) {
			nearlyLucky = false;
			break;
		}
		noOfLuckyDigits /= 10;
	}
	return isLucky || nearlyLucky;
}
int main () {
	long int n;
	cin >> n;
	if(isNearlyLucky(n)) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
	return 0;
}