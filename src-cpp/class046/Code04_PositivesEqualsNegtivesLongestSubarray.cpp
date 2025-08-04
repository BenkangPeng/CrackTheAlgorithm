/// https://www.nowcoder.com/practice/545544c060804eceaed0bb84fcd992fb

/// 思路：将正数视为1,负数视为-1,问题就转换成了和为0的最长子数组问题

#include <iostream>
#include <unordered_map>

int main() {
  int N;
  std::cin >> N;
  std::unordered_map<int, int> map{{0, 0}};

  int prefix = 0;
  int idx = 1;
  int ans = 0;
  while (N--) {
    int tmp;
    std::cin >> tmp;
    tmp = tmp > 0 ? 1 : (tmp < 0 ? -1 : 0);
    prefix += tmp;
    if (map.find(prefix) != map.end()) {
      int len = idx - map[prefix];
      ans = ans > len ? ans : len;
    } else {
      /// 只有map中没有prefix这个key时,才向map中插入,不能覆盖以前的Prefix
      map[prefix] = idx;
    }
    ++idx;
  }
  std::cout << ans << std::endl;
}