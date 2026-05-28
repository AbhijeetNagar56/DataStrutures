class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root == NULL) return {};

        vector<vector<int>> ans;
        queue<Node*> q;
        q.push(root);

        while(!q.empty()) {

            int n = q.size();
            vector<int> level;

            for(int i=0; i<n; i++) {

                level.push_back(q.front()->val);

                for(Node* c: q.front()->children) {
                    if(c != NULL) q.push(c);
                }

                q.pop();
            }
            ans.push_back(level);
        }

        return ans;
        
    }
};