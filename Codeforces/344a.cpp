#include <iostream>
#include <string>
using namespace std;
int main() {
	int n; 
	cin >> n;
    int comp=0;
    string pre = "";
    while(n--) {
        string m;
        cin >> m;
        if(pre=="") {
            comp++;
        } else {
            if(pre[1] == m[0]) {
                comp++;
            }
        }
        pre=m;
    }
    cout << comp << endl;

	return 0;
}