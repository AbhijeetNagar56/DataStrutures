
class node {
public:
    bool end;
    unordered_map<int, node*> children;
    node() {
        end = false;
    }
};

class Solution {
private:
    int m, n;
    node* root;
    vector<vector<int>> dir={{1,0},{-1,0},{0,1},{0,-1}};
    unordered_set<string> ans;
    void init() {
        root = new node();
    }

    void insert(string word) {
        node* curr = root;
        for(auto& c: word) {
            if(curr->children.find(c) == curr->children.end()) {
                curr->children[c] = new node();
            }
            curr = curr->children[c];
        }
        curr->end = true;
    }


    void dfs(int i, int j, string word, node* curr, vector<vector<bool>>& vis, vector<vector<char>>& board) {

        if(i < 0 || i >= m || j < 0 || j >= n || vis[i] [j]) {
            return;
        }
        
        char currentChar = board[i] [j];
        

        if(curr->children.find(currentChar) == curr->children.end()) {
            return;
        }
        
        node* nextNode = curr->children[currentChar];
        string nextWord = word + currentChar;

        if(nextNode->end) {
            ans.insert(nextWord);
        }
        
        vis[i][j] = true;
        
        for(auto& d : dir) {
            int ni = i + d[0];
            int nj = j + d[1];
            
            dfs(ni, nj, nextWord, nextNode, vis, board);
        }
        
        vis[i] [j] = false;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size();
        n = board[0].size();

        init();
        for(string word: words) {
            insert(word);
        }

        vector<vector<bool>> vis(m, vector<bool>(n, false));

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                
                dfs(i, j, "", root, vis, board);
            }
        }

        vector<string> present;

        for(auto& w: ans) {
            present.push_back(w);
        }

        return present;
    }
};