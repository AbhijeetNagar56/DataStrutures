class Solution {
private:
    unordered_map<int, Node*> vis;
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL) return node;

        Node* cloneNode = new Node(node->val);
        vis[node->val] = cloneNode;

        for(auto nbr: node->neighbors) {
            if(vis.find(nbr->val) == vis.end()) {
                Node* neighbors = cloneGraph(nbr);
                cloneNode->neighbors.push_back(neighbors);
            } else {
                cloneNode->neighbors.push_back(vis[nbr->val]);
            }
        }

        return cloneNode;
    }
};

