class trie {
public:
    bool isEnd;
    unordered_map<char, trie*> children;
    trie() {
        isEnd = false;
    }
};

class PrefixTree {
private:
    trie* root;
public:
    PrefixTree() {
        root = new trie();
    }
    
    void insert(string word) {
        trie* node = root;
        for(auto& c: word) {
            if(node->children.find(c) == node->children.end()) {
                node->children[c] = new trie();
            }
            node = node->children[c];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        trie* node = root;
        for(auto& c: word) {
            if(node->children.find(c) == node->children.end()) {
                return false;
            }
            node = node->children[c];
        }
        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        trie* node = root;
        for(auto& c: prefix) {
            if(node->children.find(c) == node->children.end()) {
                return false;
            }
            node = node->children[c];
        }
        return true;
    }
};
