class MinStack {
private:
    struct Element {
        int val;
        int currentMin;
    };
    std::vector<Element> stack;

public:
    MinStack() {}
    
    void push(int val) {
        int newMin = val;
        if (!stack.empty()) {
            newMin = std::min(val, stack.back().currentMin);
        }
        stack.push_back({val, newMin});
    }
    
    void pop() {
        if (!stack.empty()) {
            stack.pop_back();
        }
    }
    
    int top() {
        if (stack.empty()) return 0; // Or throw exception
        return stack.back().val;
    }
    
    int getMin() {
        if (stack.empty()) return 0; // Or throw exception
        return stack.back().currentMin;
    }
};