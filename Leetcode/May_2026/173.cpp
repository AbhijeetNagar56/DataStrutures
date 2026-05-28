class BSTIterator {
private:
    int c;
    vector<int> arr;
    void convert(TreeNode* r) {
        if(r == NULL) return;
        convert(r->left);
        arr.push_back(r->val);
        convert(r->right);
    }
public:
    BSTIterator(TreeNode* root) {
        c = 0;
        convert(root);
    }
    
    int next() {
        return arr[c++];
    }
    
    bool hasNext() {
        return c < arr.size();
    }
};