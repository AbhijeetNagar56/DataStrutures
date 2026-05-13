class MyStack {
public:
    vector<int> stack;
    int Top;
    MyStack() {
        stack = vector<int>(1000001, 0);
        Top = -1;
    }
    
    void push(int x) {
        stack[++Top] = x;
    }
    
    int pop() {
        if(empty()) return -1;
        return stack[Top--];
    }
    
    int top() {
        if(empty()) return -1;
        return stack[Top];
    }
    
    bool empty() {
        return Top == -1;
    }
};
