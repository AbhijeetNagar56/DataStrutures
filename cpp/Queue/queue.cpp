#include<iostream>
using namespace std;

// push back pop front isFull isEmpty front

class que {
private:
    int* arr;
    int front;
    int rear;
    int size;
public:
    
    que(int s) {
        arr = new int[s];
        size = s;
        front = -1;
        rear = 0;
    }
    bool isFull() {
        return rear == size;
    }

    bool isEmpty() {
        return front == -1 || front == rear;
    }

    void push(int val) {
        if(isFull()) {
            cout << "Queue Overflow" << endl;
            return;
        }
        if(front == -1) {
            front = 0;
        }
        arr[rear++] = val;
    }

    int pop() {
        if(isEmpty()) {
            cout << "Queue Underflow" << endl;
            return 0;
        }
        if(front == 0) {
            front = rear = -1;
        }
        return arr[front++];
    }

    int peek_front() {
        if(isEmpty()) {
            cout << "Queue Underflow" << endl;
            return 0;
        }
        return arr[front];
    }
};

int main() {
    que a(3);
    
    a.push(1);
    a.push(2);
    a.push(3);
    a.push(4);
    
    cout << "Top element: " << a.peek_front() << endl;
    cout << "Popped element: " << a.pop() << endl;
    cout << "Is full: " << a.isFull() << endl;
    cout << "Is empty: " << a.isEmpty() << endl;
    
    return 0;
}