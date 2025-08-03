/// https://www.nowcoder.com/practice/36fb0fd3c656480c92b569258a1223d5
#include <iostream>
#include <unordered_map>
#include <vector>

int main() {
  int N, k;
  std::cin >> N >> k;

  std::unordered_map<int, std::vector<int>> map;
  map[0].push_back(0);

  std::vector<int> prefix(N + 1);
  prefix[0] = 0;

  int tmp;
  for (int i = 1; i <= N; ++i) {
    std::cin >> tmp;
    prefix[i] = tmp + prefix[i - 1];
    map[prefix[i]].push_back(i);
  }

  int max_len = 0;
  for (int i = 0; i < N + 1; ++i) {
    if (map.find(k + prefix[i]) != map.end()) {
      int len = map[k + prefix[i]].back() - i;
      max_len = max_len > len ? max_len : len;
    }
  }
  std::cout << max_len;
  return 0;
}