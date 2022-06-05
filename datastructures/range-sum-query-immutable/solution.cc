class NumArray {
private:
    std::vector<int> presum;
public:
    NumArray(vector<int>& nums) {
        const int n = nums.size() + 1;
        presum.resize(n);
        for (int i = 1; i < n; i++) {
            presum[i] = presum[i-1] + nums[i-1];
        }
    }
    
    int sumRange(int left, int right) {
            return presum[right+1]  - presum[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 *
