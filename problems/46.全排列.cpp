/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */
#include<vector>
// @lc code=start
class Solution {
private:
    std::vector<std::vector<int>> _ans;

    void f(std::vector<int>& nums, int idx){
        int len = nums.size();

        if(idx == len - 1){
            _ans.push_back(nums);
            return;
        }

        for(int i = idx; i < len; ++i){
            std::swap(nums[idx], nums[i]);
            f(nums, idx+1);
            std::swap(nums[idx], nums[i]);
        }
   } 
public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        f(nums, 0);
        return _ans;
    }

};
// @lc code=end

