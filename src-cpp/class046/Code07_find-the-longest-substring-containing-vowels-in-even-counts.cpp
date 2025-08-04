/// https://leetcode.cn/problems/find-the-longest-substring-containing-vowels-in-even-counts/
/// 思路：用5 bits(prefix)储5位元音字母的奇偶状态,1偶0奇
/// 每遇到一个元音字母,翻转相应位
/// 向前找prefix相同(奇偶状态相同)的位置(同奇同偶)j,
/// 那么[j,i)的子数组中元音均为偶数
#include <string>
#include <unordered_map>
class Solution {
public:
  int findTheLongestSubstring(const std::string &s) {
    /// 'a'为最低位
    std::unordered_map<char, int> mask = {
        {'a', 1}, {'e', 2}, {'i', 4}, {'o', 8}, {'u', 16}};

    /// 初始状态为5'b11111
    std::unordered_map<int, int> map{{31, 0}};

    int n = s.size();
    int _mask, prefix = 31;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
          s[i] == 'u') {
        _mask = mask[s[i]];
        /// 翻转元音字母相应状态位
        prefix = prefix ^ _mask;
      }
      if (map.find(prefix) != map.end()) {
        int len = i + 1 - map[prefix];
        ans = ans > len ? ans : len;
      } else {
        map[prefix] = i + 1;
      }
    }
    return ans;
  }
};