/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */
#include<vector>
// @lc code=start
class Solution {
private:
    std::vector<std::vector<int>> ans;
    void f(std::vector<int>& nums, int idx){
        if(idx == nums.size()){
            ans.push_back(nums);
        }
        else{
            for(int k = idx; k < nums.size(); ++k){
                std::swap(nums[idx], nums[k]);
                f(nums, idx+1);
                std::swap(nums[idx], nums[k]);
            }
        }
    }
public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        f(nums, 0);
        return ans;
    }
};
// @lc code=end

