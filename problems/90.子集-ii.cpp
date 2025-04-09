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
   std::set<std::vector<int>> _ans;
   std::vector<std::vector<int>> ans;

   void f(std::vector<int>& nums, int idx){
        int len = nums.size();
        if(idx == len){
            _ans.insert(path);
            return;
        }
        else{
            path.push_back(nums[idx]);
            f(nums, idx+1);
            path.pop_back();
            f(nums, idx+1);
        }
   }

   void f2(std::vector<int>& nums, int idx){
        int len = nums.size();
        if(idx == len){
            ans.push_back(path);
            return;
        }
        else{
            int j = idx + 1;
            while(j < len && nums[j] == nums[idx]){
                ++j;
            }

            f2(nums, j);
            for(int k = idx; k < j; ++k){
                path.push_back(nums[k]);
                f2(nums,j);
            }

            for(int k = idx; k < j; ++k){
                path.pop_back();
            }
        }
   }
public:
    std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        f2(nums, 0);
        return ans;
    }
};
// @lc code=end

