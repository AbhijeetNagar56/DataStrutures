class Solution {
public:
    void helper(Node* root, vector<int>& order) {
        if (root == NULL) return;
        order.push_back(root->val);
        for(auto& child : root->children) {
            helper(child, order);
        }
    }
    vector<int> preorder(Node* root) {
        vector<int> answer;

        helper(root, answer);

        return answer;
    }
};