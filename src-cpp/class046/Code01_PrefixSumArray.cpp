/// https://leetcode.cn/problems/range-sum-query-immutable/
#include <vector>
using std::vector;
class NumArray {
private:
  std::vector<int> data;

public:
  NumArray(vector<int> &nums) : data(nums.size() + 1) {
    int n = nums.size();
    data[0] = 0;
    for (int i = 1; i <= n; ++i) {
      data[i] = nums[i - 1] + data[i - 1];
    }
  }

  int sumRange(int left, int right) { return data[right + 1] - data[left]; }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */