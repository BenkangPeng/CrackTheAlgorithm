/*
 * @lc app=leetcode.cn id=2348 lang=cpp
 *
 * [2348] 全 0 子数组的数目
 */
#include <vector>
// @lc code=start


class Solution {
public:
    long long zeroFilledSubarray(std::vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        int last_nonzero = -1;

        for(int l = 0, r = 0; r < n ; ++r){
          if(nums[r] == 0){
            ans += r - last_nonzero;
          }
          else{
            last_nonzero = r;
          }
        }
    }
};
// @lc code=end
