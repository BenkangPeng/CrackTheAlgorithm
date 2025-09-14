/*
 * @lc app=leetcode.cn id=1191 lang=cpp
 *
 * [1191] K 次串联后最大子数组之和
 */

 #include <numeric>
#include<vector>
// @lc code=start
/// 这题还得看灵神的题解：https://leetcode.cn/problems/k-concatenation-maximum-sum/solutions/3675237/fu-yong-53-ti-dai-ma-jian-ji-xie-fa-pyth-qmtp/
/// 多画前缀和曲线图去理解
class Solution {
public:

    /// @param k = 1 or 2
    /// @return k个arr拼起来后，最大子数组之和
    int maxSumSubarray(const std::vector<int>& arr, int k){
        int n = arr.size();
        int dp = arr[0];
        int ans = std::max(0, dp);

        for(int i = 1 ; i < n * k; ++i ){
            dp = std::max(dp,0) + arr[i % n];
            ans = std::max(dp,ans);
        }

        return ans;
    }
    int kConcatenationMaxSum(std::vector<int>& arr, int k) {
        if(k < 3){
            return maxSumSubarray(arr, k);
        }

        /// k >= 3
        constexpr int mod = int(1e9 + 7);
        long long ans = maxSumSubarray(arr, 2);
        int sum = std::accumulate(arr.begin(),arr.end(),0);
        if(sum >= 0){
            ans = (ans + (long long)sum * (k-1)) % mod; 
            return ans;
        }
        else{
            return maxSumSubarray(arr, 1);
        }
    }
};
// @lc code=end

