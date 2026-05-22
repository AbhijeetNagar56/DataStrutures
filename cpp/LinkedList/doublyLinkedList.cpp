#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* pre;

    Node(int val) {
        this->val = val;
        this->next = this->pre = nullptr;
    }
};

class doubleLinkedList {
public:
    Node* head;
    Node* tail;
    
    doubleLinkedList() {
        this->head = nullptr;
        this->tail = nullptr;
    }

    void append(int key) {
        Node* newNode = new Node(key);
        if(this->head == nullptr && this->tail == nullptr) {
            this->head = this->tail = newNode;
            return;
        }
        this->tail->next = newNode;
        newNode->pre = this->tail;
        this->tail = newNode;
    }

	void prepend(int key) {
		Node* newNode = new Node(key);
		if(this->head == nullptr && this->tail == nullptr) {
			this->head = this->tail = newNode;
			return;
		}
		newNode->next = this->head;
		this->head->pre = newNode;
		this->head = newNode;
	}

    void deleteNode(int key) {
        if(this->head == nullptr) {
            return;
        }
        
        // Case: deleting head
        if(this->head->val == key) {
            Node* temp = this->head;
            this->head = this->head->next;
            if(this->head != nullptr) {
                this->head->pre = nullptr;
            } else {
                // List is now empty
                this->tail = nullptr;
            }
            delete temp;
            return;
        }

        Node* temp = this->head;
        while(temp->next != nullptr && temp->next->val != key) {
            temp = temp->next;
        }
        
        if(temp->next == nullptr) {
            return; // Not found
        }
        
        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        
        if(temp->next != nullptr) {
            temp->next->pre = temp;
        } else {
            // We deleted the tail
            this->tail = temp;
        }
        
        delete nodeToDelete;
    }

    void display() {
        if(this->head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        Node* temp = this->head;
        while(temp) {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    bool empty() {
        return this->head == nullptr;
    }

    int size() {
        int count = 0;
        Node* temp = this->head;
        while(temp) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    int search(int key) {
        int index = 0;
        Node* temp = this->head;
        while(temp) {
            // FIXED: Use == for comparison
            if(temp->val == key) return index;
            index++;
            temp = temp->next;
        }
        return -1;
    }
};

int main() {
    doubleLinkedList dll;
    dll.append(1);
    dll.append(2);
    dll.append(3);
    dll.display(); // Output: 1 2 3
    
    cout << "Size: " << dll.size() << endl;
    cout << "Search 2 at index: " << dll.search(2) << endl;
    cout << "Search 5 at index: " << dll.search(5) << endl;
    
    dll.deleteNode(2);
    dll.display(); // Output: 1 3
    
    dll.deleteNode(1);
    dll.display(); // Output: 3
    
    dll.deleteNode(3);
    dll.display(); // Output: List is empty
    
    return 0;
}