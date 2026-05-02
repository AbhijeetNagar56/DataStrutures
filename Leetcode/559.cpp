class Solution {
public:
    int maxDepth(Node* root) {
        if(root == NULL) return 0;

        int max_depth = 0;
        for (auto& child: root->children) {
            max_depth = max(max_depth, maxDepth(child));
        }

        return 1 + max_depth;
    }
};