class node {
public:
    int key;
    int val;
    node *prev, *next;
    node(int k, int v) {
        key = k;
        val = v;
        prev = next = nullptr;
    }
};


class LRUCache {
private:
    node* head;
    node* tail;
    int cap;
    unordered_map<int, node*> hm;

    void remove(node* Node) {
        Node->prev->next =Node->next;
        Node->next->prev = Node->prev;
    }

    void insert(node* newNode) {
        node* prev = tail->prev;
        prev->next = newNode;
        newNode->prev = prev;
        newNode->next = tail;
        tail->prev = newNode;
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        hm.clear();
        head = new node(0, 0);
        tail = new node(0, 0);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(hm.find(key) == hm.end()) {
            return -1;
        }
        node* Node = hm[key];
        remove(Node);
        insert(Node);
        return Node->val;
    }
    
    void put(int key, int value) {
        if(hm.find(key) != hm.end()) {
            remove(hm[key]);
        }

        node* newNode = new node(key, value);
        hm[key] = newNode;
        insert(newNode);

        if(hm.size()>cap) {
            node* lru = head->next;
            remove(lru);
            hm.erase(lru->key);
            delete lru;
        }
    }
};
