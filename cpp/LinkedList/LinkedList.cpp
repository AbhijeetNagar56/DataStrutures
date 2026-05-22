#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node(int val) {
        this->val = val;
        this->next = nullptr;
    }
};

class LinkedList {
public:
    Node* head;
    LinkedList() {
        this->head = nullptr;
    }

    void append(int val) {
        Node* newNode = new Node(val);
        if (this->head == nullptr) {
            this->head = newNode;
            return;
        }
        Node* temp = this->head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void prepend(int val) {
        Node* newNode = new Node(val);
        if (this->head == nullptr) {
            this->head = newNode;
            return;
        }
        newNode->next = this->head;
        this->head = newNode;
    }

    void deleteNode(int val) {
        if (this->head == nullptr) {
            return;
        }

        if(this->head->val == val) {
            Node* temp = this->head;
            this->head = this->head->next;
            delete temp;
            return;
        }

        Node* temp = this->head;

        while(temp->next != nullptr && temp->next->val != val) {
            temp = temp->next;
        }

        if(temp->next == nullptr) {
            return;
        }

        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
    }

    void display() {
        Node* temp = this->head;
        while (temp != nullptr) {
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
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    int search(int val) {
        Node* temp = this->head;
        int index = 0;
        while (temp != nullptr) {
            if (temp->val == val) {
                return index;
            }
            temp = temp->next;
            index++;
        }
        return -1; // Value not found
    }

};

int main () {
    LinkedList list;
    cout << "Is list empty? " << list.empty() << endl; // Output: Is list empty? 1
    list.append(10);
    list.append(20);
    list.append(30);
    list.display(); // Output: 10 20 30
    list.prepend(5);
    list.display(); // Output: 5 10 20 30
    list.deleteNode(20);
    list.display(); // Output: 5 10 30
    cout << "Size: " << list.size() << endl; // Output: Size: 3
    cout << "Search for 10: " << list.search(10) << endl; // Output: Search for 10: 1
    cout << "Search for 40: " << list.search(40) << endl; // Output: Search for 40: -1
    return 0;
}