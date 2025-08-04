/// https://leetcode.cn/problems/longest-well-performing-interval/description/

#include <unordered_map>
#include <vector>
class Solution {
public:
  int longestWPI(std::vector<int> &hours) {
    int n = hours.size();
    std::unordered_map<int, int> map{{0, 0}};
    int prefix = 0, ans = 0;
    for (int i = 0; i < n; ++i) {
      prefix += hours[i] > 8 ? 1 : -1;
      if (prefix > 0) {
        ans = i + 1; /// [0,i)的前缀和>0, [0,i)就是以i-1为右端点的最长子数组
      } else {
        /// 如果prefix < 0, 就去找有没有前缀和为prefix-1(idx=j)的点
        /// 使得这段子数组[j,i)前缀和为1
        if (map.find(prefix - 1) != map.end()) {
          int len = i - map[prefix - 1];
          ans = ans > len ? ans : len;
        } /// else 以i-1为右端点的子数组前缀和一定<=0
      }

      if (map.find(prefix) == map.end()) {
        map[prefix] = i;
      }
    }

    return ans;
  }
};