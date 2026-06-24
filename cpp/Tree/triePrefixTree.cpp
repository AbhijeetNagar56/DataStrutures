#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;


class TrieNode {
public:
    bool isEndOfWord;
    unordered_map<char, TrieNode*> children;
    TrieNode() {
        isEndOfWord = false;
    }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->children.find(c) == node->children.end()) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->isEndOfWord = true;
    }

    bool search(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->children.find(c) == node->children.end()) {
                return false;
            }
            node = node->children[c];
        }
        return node->isEndOfWord;
    }

    bool startsWith(const string& prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            if (node->children.find(c) == node->children.end()) {
                return false;
            }
            node = node->children[c];
        }
        return true;
    }
};


int main() {

    string w1 = "book";
    string w2 = "box";
    string w3 = "bag";
    string w4 = "band";

    Trie prefix_tree;
    prefix_tree.insert(w1);
    prefix_tree.insert(w2);
    prefix_tree.insert(w3);
    prefix_tree.insert(w4);

    prefix_tree.search("boot") ? cout << "yes" : cout << "no";
    cout << "\n";
    return 0;
}