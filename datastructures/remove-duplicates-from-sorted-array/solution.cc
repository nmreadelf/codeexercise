class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    if (nums.empty()) {
      return 0;
    }
    int slow = 0;
    int fast = 0;

    const int n = nums.size();
    while (fast < n) {
      if (nums[fast] != nums[slow]) {
        slow++;
        nums[slow] = nums[fast];
      }
      fast++;
    }
    return slow + 1;
  }
};
