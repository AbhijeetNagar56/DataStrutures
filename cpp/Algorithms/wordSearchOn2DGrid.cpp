#include <iostream>
#include <vector>
#include <string>
using namespace std;


bool dfs(int i, int j, int n, int idx, string& word, vector<vector<bool>>& vis, vector<vector<char>>& grid) {
    if(idx >= word.length()) {
        return true;
    }

    if(i<0 || i>=n || j<0 || j>=n || vis[i][j] || grid[i][j] != word[idx]) {
        return false;
    }

    vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

    vis[i][j] = true;

    for(auto& d: dir) {
        int ni = i + d[0];
        int nj = j + d[1];
        if(dfs(ni, nj, n, idx+1, word, vis, grid)) return true;
    }

    vis[i][j] = false;

    return false;
}

bool find(int n, string& word, vector<vector<char>>& grid) {

    vector<vector<bool>> vis(n, vector<bool> (n, false));

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(dfs(i, j, n, 0, word, vis, grid)) return true;
        }
    }

    return false;
}

int main() {
    int n;
    cin >> n;

    vector<vector<char>> grid(n, vector<char> (n, '.'));
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> grid[i][j];
        }
    }
    
    string word;
    cin >> word;

    if(find(n, word, grid)) {
        cout << word << " is present." << "\n";
    } else {
        cout << word << " is not present." << "\n";
    }

    return 0;
}