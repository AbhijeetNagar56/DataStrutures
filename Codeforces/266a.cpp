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
