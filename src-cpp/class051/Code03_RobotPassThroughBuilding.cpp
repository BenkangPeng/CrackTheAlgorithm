/// https://www.nowcoder.com/practice/7037a3d57bbd4336856b8e16a9cafd71

#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

int main() {
  int N;
  std::cin >> N;
  std::vector<int> H;
  H.reserve(N + 1);
  H.push_back(0);

  int tmp;
  for (int i = 0; i < N; ++i) {
    std::scanf("%d", &tmp);
    H.push_back(tmp);
  }

  int maxH = *std::max_element(H.begin(), H.end());

  int l = 1, r = 100'000;
  int mid, ans;

  /// 能量为E，能否跳完所有building
  auto f = [&](int E) {
    for (int i = 0; i < N; ++i) {
      E += E - H[i + 1];
      if (E < 0) {
        return false;
      }
      /// 这里太阴了, E可能一直在增长，超int了
      //  提前判断返回
      if (E > maxH) {
        return true;
      }
    }
    return true;
  };

  while (l <= r) {
    mid = l + ((r - l) >> 1);

    if (f(mid)) {
      ans = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  std::cout << ans << std::endl;
}