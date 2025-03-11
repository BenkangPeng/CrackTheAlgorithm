//90. 子集II https://leetcode.cn/problems/subsets-ii/description/
/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 * `nums` is not a set in a true sense, as it contains duplicate elements. 
 * It's a combination problem of nums, actually.
 */
#include<vector>
#include<set>
#include<algorithm>
// @lc code=start
class Solution {
private:
    std::vector<int> path;
    std::vector<std::vector<int>> ans;

    void f(const std::vector<int>& nums, int i){
        if(i == nums.size()){
            ans.push_back(path);
        }
        else{
            int j = i + 1;
            while(j < nums.size() && nums[j] == nums[i]){
                ++j;
            }

            f(nums, j);
            for(int k = i; k < j; ++k){
                path.push_back(nums[i]);
                f(nums, j);
            }

            //回溯，恢复现场
            for(int k = i; k < j; ++k){
                path.pop_back();
            }
        }
    }
public:
    std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) {
        sort(nums.begin(), nums.end());//排序后再处理，相当于剪去了一些重复的分支
        f(nums, 0);
        return ans;
    }
};
// @lc code=end

