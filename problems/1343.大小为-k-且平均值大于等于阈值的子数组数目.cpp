/*
 * @lc app=leetcode.cn id=1343 lang=cpp
 *
 * [1343] 大小为 K 且平均值大于等于阈值的子数组数目
 */
#include<vector>
// @lc code=start
class Solution {
public:
    int numOfSubarrays(std::vector<int>& arr, int k, int threshold) {
        
        int n = arr.size();
        long long sum = 0;
        int ans = 0;
        for(int l = 0, r = 0; r < n;++r ){
            sum += arr[r];

            if(r - l + 1 == k){
                if(sum / k >= threshold){
                    ans++;
                }
                sum -= arr[l++];
            }
        }
        return ans;
    }
};
// @lc code=end

