class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* tmp = head;
        unordered_map<Node*, Node*> ht;
        ht[NULL] = NULL;
        while(tmp) {
            Node* cpy = new Node(tmp->val);
            ht[tmp] = cpy;
            tmp = tmp->next;
        }
        tmp = head;
        while(tmp) {
            Node* cpy = ht[tmp];
            cpy->next = ht[tmp->next];
            cpy->random = ht[tmp->random];
            tmp = tmp->next;
        }

        return ht[head];
    }
};