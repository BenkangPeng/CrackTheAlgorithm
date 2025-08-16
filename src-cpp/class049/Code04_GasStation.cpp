/// https://leetcode.cn/problems/gas-station/description/

#include <vector>

class Solution {
public:
  int canCompleteCircuit(std::vector<int> &gas, std::vector<int> &cost) {
    /// 从i到i+1的净耗油量
    std::vector<int> rest(gas);
    int n = gas.size();
    for (int i = 0; i < n; ++i) {
      rest[i] -= cost[i];
    }

    /// 油箱中的油量
    int sum = 0;
    for (int l = 0, r = 0; l < n;) {
      /// 不断扩展窗口右边界
      while (sum >= 0) {
        /// 用取模去解决绕圈的问题
        sum += rest[r % n];

        /// 如果右边界r绕了一圈
        if (r > l && r % n == l) {
          return l;
        }
        ++r;
      }

      /// 从l出发,最多到达r-1,即窗口为[l,r-1](从r-1无法到达r)
      /// 任意x \in [l,r-1] 也无法到达r, 即任意x无法绕一圈回到x
      /// 此时l可以从r开始去遍历寻找答案
      l = r;
      r = l;
      sum = 0;
    }

    return -1;
  }
};

/// 超时了,复杂度为O(N^2)
class Solution2 {
public:
  int canCompleteCircuit(std::vector<int> &gas, std::vector<int> &cost) {

    for (int i = 0; i < gas.size(); ++i) {
      int j = i;
      int _gas = 0;
      bool over = false;
      do {
        _gas += gas[j];
        if (_gas < cost[j]) {
          break;
        } else {
          _gas -= cost[j];
          if (j == gas.size() - 1) {
            j = 0;
            over = true;
          } else {
            ++j;
          }
        }
      } while (i != j);

      if (over && i == j) {
        return i;
      }
    }

    return -1;
  }
};