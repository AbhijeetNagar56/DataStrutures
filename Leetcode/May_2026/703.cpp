class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> heap;
    int rank;
public:
    KthLargest(int k, vector<int>& nums) {
        rank = k;
        for(int n: nums) {
            heap.push(n);
            if(heap.size() > rank) {
                heap.pop();
            }
        }
    }
    
    int add(int val) {
        heap.push(val);
        while(heap.size() > rank) {
            heap.pop();
        }
        return heap.top();
    }
};
