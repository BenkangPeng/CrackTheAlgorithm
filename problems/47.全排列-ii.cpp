/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */
#include<vector>
#include<unordered_set>
// @lc code=start
class Solution {
private:
    std::vector<std::vector<int>> ans;
    void f(std::vector<int>& nums, int idx){
        if(idx == nums.size()){
            ans.push_back(nums);
        }
        else{
            std::unordered_set<int> S;
            for(int k = idx; k < nums.size(); ++k){
                if(!S.contains(nums[k])){
                    S.insert(nums[k]);
                    std::swap(nums[idx], nums[k]);
                    f(nums, idx+1);
                    std::swap(nums[idx], nums[k]);
                }
            }
        }
    }
public:
    std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) {
       f(nums, 0);
       return ans; 
    }
};
// @lc code=end

