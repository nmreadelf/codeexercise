class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int fast = 0;
        int slow = 0;
        const int n = nums.size();
        while (fast < n) {
            if (nums[fast] != val) {
                nums[slow] = nums[fast];
                slow++;
            }
            fast ++;
        }
        return slow;
    }
};
