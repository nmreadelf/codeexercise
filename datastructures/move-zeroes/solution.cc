class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int fast = 0, slow = 0;
        while (fast < nums.size()) {
            if (nums[fast] != val) {
                nums[slow] = nums[fast];
                slow++;
            }
            fast++;
        }
        return slow;
    }
    void moveZeroes(vector<int>& nums) {
        int p = removeElement(nums, 0);

        for (; p < nums.size(); p++) {
            nums[p] = 0;
        }
    }
};
