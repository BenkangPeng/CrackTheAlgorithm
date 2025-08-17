/*
 * @lc app=leetcode.cn id=643 lang=cpp
 *
 * [643] 子数组最大平均数 I
 */
#include<vector>
// @lc code=start
class Solution {
public:
    double findMaxAverage(std::vector<int>& nums, int k) {
        
        int n = nums.size();
        long long sum = 0, ans = INT_MIN;
        for(int l = 0, r = 0; r < n ; ++r){
            sum += nums[r];
            if(r - l + 1 == k){
                ans = sum > ans ? sum : ans;
                sum -= nums[l++];
            }
        }

        return ans / (double)k;
    }
};
// @lc code=end

