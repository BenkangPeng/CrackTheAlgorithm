///  940. https://leetcode.cn/problems/distinct-subsequences-ii/description/

//// 假设s = "aba", all = 1(空集{})
/// i = 0, all中子串结尾加上a, 新增new_add = 1, all = 2 ({},a)
/// i = 1, all中子串结尾加上b, 新增new_add = 2, all = 4 ({},a,b,ab)
/// i = 2, all中子串结尾加上a, 新增new_add = all - dp[a] = 2, all = 6
/// ({},a,b,ab,aa,ba,aba)
#include <string>
#include <vector>

class Solution {
public:
  int distinctSubseqII(const std::string &s) {
    constexpr int mod = 1'0000'00007;
    int n = s.size();
    /// 记录以某个字母结尾的子串的个数
    std::vector<int> dp(26, 0);

    /// 子串总和
    int all = 1; // 假设答案中包含一个空集{},之后会减去

    for (int i = 0; i < s.size(); ++i) {
      int idx = s[i] - 'a';

      /// 例如s[i] = 'b', 将当前all中所有子串结尾都加上b, 将得到all个新子串
      /// 但新增的all个子串中有dp[idx]个子串, 与旧的all个子串中重复
      int new_add = (all - dp[idx]) % mod;
      dp[idx] = (dp[idx] + new_add) % mod;
      all = (all + new_add) % mod;
    }

    return (all - 1 + mod) % mod;
  }
};