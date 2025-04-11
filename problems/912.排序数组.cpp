/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 */

#include<vector>
using std::vector;
// @lc code=start
class Solution {
    void swap(int& a, int& b){
        int t = a;
        a = b;
        b = t;
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        int len = nums.size();
        if(len < 2) return nums;

        for(int i = 0 ; i < len ; ++i){
            int minIdx = i;
            for(int j = i + 1; j < len; ++j){
                if(nums[minIdx] > nums[j])  minIdx = j;
            }
            std::swap(nums[i], nums[minIdx]);
        }
        return nums;
    }
};
// @lc code=end

