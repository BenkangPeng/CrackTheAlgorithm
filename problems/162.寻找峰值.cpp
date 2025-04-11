/*
 * @lc app=leetcode.cn id=162 lang=cpp
 *
 * [162] 寻找峰值
 */

#include<vector>
#include<iostream>
using std::vector;
// @lc code=start
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int len = nums.size();
        if(len == 1)    return 0;

        if(nums[0] > nums[1])   return 0;
        if(nums[len-1] > nums[len-2])   return len-1;

        int l = 1, r = len - 2;
        int mid;

        while(l <= r){//不是l < r要加个=
            mid = l + ((r-l) >> 1);
            if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]){
                return mid;
            }
            else if(nums[mid] < nums[mid-1]){
                r = mid -1;//注意
            }
            else{
                l = mid + 1;//注意
            }
        }

        return -1;
    }
};
// @lc code=end