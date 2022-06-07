class Solution {
public:
  bool carPooling(vector<vector<int>> &trips, int capacity) {
    std::vector<int> diff_(1001);
    for (const auto &trip : trips) {
      int val = trip[0];
      int i = trip[1];
      int j = trip[2] - 1;
      diff_[i] += val;
      diff_[j + 1] -= val;
    }

    for (int i = 1; i < diff_.size(); i++) {
      diff_[i] = diff_[i - 1] + diff_[i];
    }

    for (int i = 0; i < diff_.size(); i++) {
      if (capacity < diff_[i]) {
        return false;
      }
    }
    return true;
  }
};
