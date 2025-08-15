/// https://leetcode.cn/problems/minimum-window-substring/description/

#include <iostream>
#include <string>
#include <unordered_map>

/// 太慢了,尤其是check()的反复调用
/// 太保守的左边界左移策略
class Solution1 {
private:
  /// 检查是否已经收集全了t中所需字符
  bool check(const std::unordered_map<char, int> &count) {
    for (auto pair : count) {
      if (pair.second > 0) {
        return false;
      }
    }
    return true;
  }

public:
  std::string minWindow(const std::string &s, const std::string &t) {
    std::unordered_map<char, int> count;
    for (char ch : t) {
      count[ch]++;
    }

    int n = s.size();
    std::string ans = s;
    for (int l = 0, r = 0; r < n; ++r) {
      /// 该字符是t中需要的
      if (count.find(s[r]) != count.end()) {
        count[s[r]]--;
      }

      while (check(count)) {
        /// 如果左边界的字符不是t中所需的字符
        if (count.find(s[l]) == count.end()) {
          /// 缩小左边界
          l++;
        } else {
          /// 左边界缩小后,窗口中不包含所有t中字符了
          if (count[s[l]] + 1 > 0) {
            break;
          } else {
            /// 缩小左边界
            count[s[l]]++;
            l++;
          }
        }
      }

      if (check(count)) {
        ans = ans.size() > r - l + 1 ? s.substr(l, r - l + 1) : ans;
      }
    }

    return check(count) ? ans : "";
  }
};

class Solution {

public:
  std::string minWindow(const std::string &s, const std::string &t) {
    std::unordered_map<char, int> count;
    for (char ch : t) {
      count[ch]++;
    }

    int n = s.size(), cnt = 0;
    /// 最大左边界, 字符串最小长度
    int max_l = 0, min_size = s.size() + 1;
    for (int l = 0, r = 0; r < n; ++r) {
      /// 该字符是t中需要的
      if (count.find(s[r]) != count.end()) {
        count[s[r]]--;
        if (count[s[r]] >= 0) {
          /// cnt用于计数: 收集了几个t中的字符
          /// @attention 只有count[s[r]] > 0时这时收集的字符s[r]才是"刚需"的字符
          /// 否则为过度(重复)收集
          ++cnt;
        }
      }

      /// 窗口中包含所有t中字符
      while (cnt == t.size()) {
        if (min_size > r - l + 1) {
          max_l = l;
          min_size = r - l + 1;
        }
        if (count.find(s[l]) != count.end() && ++count[s[l]] > 0) {
          --cnt;
        }
        ++l;
      }
    }

    return min_size == s.size() + 1 ? "" : s.substr(max_l, min_size);
  }
};