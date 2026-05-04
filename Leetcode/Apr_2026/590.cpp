class Solution {
public:
    void helper(Node* root, vector<int>& order) {
        if (root == NULL) return;
        for(auto& child : root->children) {
            helper(child, order);
        }
        order.push_back(root->val);
    }
    vector<int> postorder(Node* root) {
        vector<int> answer;

        helper(root, answer);

        return answer;
    }
};