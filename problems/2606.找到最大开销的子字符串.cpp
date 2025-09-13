/*
 * @lc app=leetcode.cn id=2606 lang=cpp
 *
 * [2606] 找到最大开销的子字符串
 */

 #include <climits>
#include<vector>
 #include<string>
 using std::vector;
 using std::string;
// @lc code=start
class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
       std::vector<int> char_value(26,0);
       for(int i = 0; i < 26; ++i){
        char_value[i] = i + 1;
       }

       for(int i = 0; i < chars.size(); ++i){
        int idx = chars[i] - 'a';
        char_value[idx] = vals[i]; 
       }

       int n = s.size();
       std::vector<int> prefix(n + 1, 0);
       for(int i = 0; i < n; ++i){
            prefix[i+1] = prefix[i] + char_value[s[i] - 'a'];
       }

       int past = prefix[n] - prefix[n-1];
       int cur = 0;
       int ans = past;
       for(int i = n - 2 ; i >= 0; --i){
         cur = std::max(prefix[i+1] - prefix[i], prefix[i+1] - prefix[i] + past);
         past = cur;
         ans = std::max(ans,cur);
       }

       return ans < 0 ? 0 : ans;
    }
};
// @lc code=end

