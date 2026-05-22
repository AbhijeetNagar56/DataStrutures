// 617A - Elephant
// #include <iostream>
// using namespace std;

// int main() {
// 	int dist;
// 	cin >> dist;
// 	int step;
// 	while(dist > 0) {
// 		step++;
// 		dist -= 5;
// 	}
// 	cout << step << endl;
// 	return 0;
// }


// 266A
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	int size;
	cin >> size;
    string str;
    cin >> str;
    stack<char> s;
    for(char c: str) {
        if(!s.empty() && s.top() == c) {
            continue;
        } else {
            s.push(c);
        }
    }
    cout << size - s.size() << endl;
	return 0;
}
