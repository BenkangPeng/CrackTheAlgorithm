/// https://leetcode.cn/problems/subarray-sum-equals-k/
#include <iostream>
#include <unordered_map>
#include <vector>

using std::vector;
class Solution {
public:
  int subarraySum(vector<int> &nums, int k) {
    std::unordered_map<int, int> map{{0,1}};/// 前缀和数组中, 0的个数为1
    int ans = 0, prefix = 0;
    for(int num: nums){
        prefix += num;
        ans += map.count(prefix-k) ? map[prefix-k] : 0;
        map[prefix]++;
    }
    return ans;
  }
};

int main() {
  std::vector<int> nums = {-1, -1, 1};
  Solution ss;
  std::cout << ss.subarraySum(nums, 1);
  return 0;
}