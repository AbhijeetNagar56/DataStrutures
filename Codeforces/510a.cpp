#include <iostream>
using namespace std;
void draw(int n, int m) {
    bool isRight = true;
    for(int i=0; i<n; i++) {
        if(i % 2 != 0) {
            if(!isRight) {
                cout << "#";
            } else {
                cout << ".";
            }
            for(int j=0; j<m-2; j++) {
                cout << ".";
            }
            if(isRight) {
                cout << "#";
            } else {
                cout << ".";
            }

            isRight = !isRight;
        } else {
            for(int j=0; j<m; j++) {
                cout << "#";
            }
        }
        cout << "\n";
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    draw(n, m);
    return 0;
}