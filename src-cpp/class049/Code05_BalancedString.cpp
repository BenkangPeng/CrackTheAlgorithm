/// https://leetcode.cn/problems/replace-the-substring-for-balanced-string/description/
/// 思路: 寻找哪个字符多余,哪个字符缺少
/// 例如,s = "QQWE", 则Q多出一个, 缺少一个R
/// 问题可以转换成: 寻找最短的包含一个Q的子串,把该子串中的一个Q改成R即可
/// 再例如, s = "QQWWERQW"多出一个Q,一个W(缺少一个E,R),
/// 问题转换成找到一个最短的包含一个Q一个W的子串,返回其长度
#include <climits>
#include <iostream>
#include <string>
#include <unordered_map>

class Solution {

public:
  int balancedString(const std::string &s) {
    int n = s.size();
    std::unordered_map<char, int> count;

    /// 统计各字符个数(s中只包含QWER四种字符)
    for (char ch : s) {
      ++count[ch];
    }

    /// 得到s中多余的字符及其多余的个数

    int need = (n >> 2);
    /// 多余的字符总个数
    /// 使用cnt来判断当前窗口是否包含所有多余的字符
    int cnt = 0;
    for (char ch : "QWER") {
      count[ch] = count[ch] > need ? count[ch] - need : 0;
      cnt += count[ch];

      if (count[ch] == 0) {
        count.erase(ch);
      }
    }

    /// 已经是平衡字符串
    if (cnt == 0) {
      return 0;
    }

    int ans = INT_MAX;
    for (int l = 0, r = 0; r < n; ++r) {
      if (count.find(s[r]) != count.end()) {
        count[s[r]]--;
        if (count[s[r]] >= 0) {
          cnt--;
        }
      }

      /// 收缩左边界
      while (cnt == 0) {
        ans = ans > r - l + 1 ? r - l + 1 : ans;

        if (count.find(s[l]) != count.end()) {
          count[s[l]]++;
          if (count[s[l]] > 0) {
            cnt++;
          }
        }
        l++;
      }
    }
    return ans == INT_MAX ? 0 : ans;
  }
};

int main() {
  Solution ss;
  std::string str = "QQWE";
  std::cout << ss.balancedString(str) << std::endl;
}