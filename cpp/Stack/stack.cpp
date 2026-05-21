#include<iostream>
using namespace std;

class stack {
private:
    int* arr;
    int top;
    int size;
public:
    
    stack(int s) {
        arr = new int[s];
        size = s;
        top = -1;
    }
    bool isFull() {
        return top == size - 1;
    }

    bool isEmpty() {
        return top == -1;
    }

    void push(int val) {
        if(isFull()) {
            cout << "Stack Overflow" << endl;
            return;
        }
        arr[++top] = val;
    }

    int pop() {
        if(isEmpty()) {
            cout << "Stack Underflow" << endl;
            return 0;
        }
        return arr[top--];
    }

    int peek() {
        if(isEmpty()) {
            cout << "Stack Underflow" << endl;
            return 0;
        }
        return arr[top];
    }
};

int main() {
    stack a(3);
    
    a.push(1);
    a.push(2);
    a.push(3);
    a.push(4);
    
    cout << "Top element: " << a.peek() << endl;
    cout << "Popped element: " << a.pop() << endl;
    cout << "Is full: " << a.isFull() << endl;
    cout << "Is empty: " << a.isEmpty() << endl;
    
    return 0;
}