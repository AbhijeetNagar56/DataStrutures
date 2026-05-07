class NumArray {
private:
    vector<int> arr;
public:
    
    NumArray(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) arr.push_back(nums[i]);
    }
    
    int sumRange(int left, int right) {
        int ptr = left, sum = 0;
        while(ptr <= right) sum += arr[ptr++];
        return sum;
    }
};