class MyQueue {
public:
    vector<int> que;
    int front, rear;

    MyQueue() {
        que = vector<int>(1000001, 0);
        front = 0;
        rear = -1;
    }
    
    void push(int x) {
        que[++rear] = x;
    }
    
    int pop() {
        if(empty()) return -1;
        return que[front++];
    }
    
    int peek() {
        if(empty()) return -1;
        return que[front];
    }
    
    bool empty() {
        return front > rear;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */