#include <iostream>
using namespace std;


void toh(int n, char s, char a, char d){
    if(n==0){
        return;
    }
    toh(n-1, s, d, a);
    cout << "Transfer disk " << n <<" from " << s << " to " << d << endl;
    toh(n-1, a, s, d);
}

int main () {

    toh(3, 'A', 'B', 'C');
    return 0;
}