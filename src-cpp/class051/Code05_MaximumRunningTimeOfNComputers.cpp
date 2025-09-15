#include <vector>
using std::vector;
class Solution0 {
public:
  long long maxRunTime(int n, vector<int> &batteries) {
    long long l = 1, r = static_cast<long long>(1e14);
    long long mid, ans;

    while (l <= r) {
      mid = l + ((r - l) >> 1);
      if (f(batteries, n, mid)) {
        ans = mid;
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }

    return ans;
  }

  /// 这道题难就难在这个f函数的实现
  /// 电池能否支持n台电脑运行time时间
  /// 写不清楚，参考左神的讲解：https://www.bilibili.com/video/BV1Mh4y1P7qE?t=5281.2
  /// 灵神的题解：https://leetcode.cn/problems/maximum-running-time-of-n-computers/solutions/1214440/liang-chong-jie-fa-er-fen-da-an-pai-xu-t-grd8/
  bool f(vector<int> &batteries, int n, long long time) {
    long long sum = 0; /// 碎片电池的总量
    for (int battery : batteries) {
      /// 电量>time的电池只能用到time的电量，剩余battery-time的电量用不到(只要求所有电脑运行时间time)
      /// 因此>time的电池搞定一台电脑的供电就行了
      if (battery > time) {
        n--; // 每个电量>time的电池负责一台电脑的运行
      } else {
        /// < time的电池，称为碎片电池，无法完整供应电脑运行时间time
        /// 只能组合在一起为电脑供电
        /// 计算碎片电池的电量和
        sum += battery;
      }

      /// 如果碎片电池电量和 > 待供电电脑数量 * time
      /// 总能通过合理调度实现所有电脑有电
      /// 见https://i0.hdslb.com/bfs/new_dyn/522cabd027c89bda19fd0212f114f5f0668698003.png@480w_248h_1s.avif
      if (sum >= n * time) {
        return true;
      }
    }
    return false;
  }
};

/// 优化
class Solution {
public:
  long long maxRunTime(int n, vector<int> &batteries) {
    long long total = 0;
    int max = 0;
    for (int battery : batteries) {
      max = std::max(battery, max);
      total += battery;
    }

    /// 加一个提前判断
    if (total > static_cast<long long>(max) * n) {
      // 所有电池的最大电量是max
      // 如果此时total > max * num，
      // 说明 : 最终的供电时间一定在 >= max，而如果最终的供电时间 >= max
      // 说明 : 对于最终的答案X来说，所有电池都是课上讲的"碎片拼接"的概念
      // 那么寻找 ? * num <= sum 的情况中，尽量大的 ? 即可
      // 即sum / num
      return total / n;
    }

    long long l = 1, r = total / n; /// 时间的可能的最大值为total/n
    long long ans, mid;
    while (l <= r) {
      mid = l + ((r - l) >> 1);
      if (f(batteries, n, mid)) {
        ans = mid;
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }

    return ans;
  }

  /// 与Solution0的f是一样的
  bool f(vector<int> &batteries, int n, long long time) {
    long long sum = 0; /// 碎片电池的总量
    for (int battery : batteries) {
      /// 电量>time的电池只能用到time的电量，剩余battery-time的电量用不到(只要求所有电脑运行时间time)
      /// 因此>time的电池搞定一台电脑的供电就行了
      if (battery > time) {
        n--; // 每个电量>time的电池负责一台电脑的运行
      } else {
        /// < time的电池，称为碎片电池，无法完整供应电脑运行时间time
        /// 只能组合在一起为电脑供电
        /// 计算碎片电池的电量和
        sum += battery;
      }

      /// 如果碎片电池电量和 > 待供电电脑数量 * time
      /// 总能通过合理调度实现所有电脑有电
      /// 见https://i0.hdslb.com/bfs/new_dyn/522cabd027c89bda19fd0212f114f5f0668698003.png@480w_248h_1s.avif
      if (sum >= n * time) {
        return true;
      }
    }
    return false;
  }
};