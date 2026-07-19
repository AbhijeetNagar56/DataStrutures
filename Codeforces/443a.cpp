#include <iostream>
#include <string>
#include <sstream>
#include <unordered_set>
using namespace std;
int main() {
    string s;
    getline(cin, s);
    unordered_set<int> Set;
    stringstream input(s);
    int i=0;
    while(i<s.length()) {
        char ch;
        input >> ch;
        if(ch >= 'a' && ch <='z') {
            Set.insert(ch);
        }
        i++;
    }
    cout << Set.size() << "\n";
    return 0;
}