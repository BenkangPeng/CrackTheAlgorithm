/// https://www.luogu.com.cn/problem/P4231
/// 思路: 常规的一阶差分做不到,要用两阶差分
/// [l,r]上各个元素分别加 s,s+d,s+2d......s+nd(=e); 其中d = (e - s) / (r - l)
/// 对上述数组求一阶差分[l,r+1]: s,d,d,d......d,-e
/// 再求一阶差分[l,r+2]: s,d-s,0,0,0......0,-e-d,e
/// 综上,对于一组(l,r,s,e)
///     ans[l] += s;
// ans[l + 1] += d - s;
// ans[r + 1] += -e - d;
// ans[r + 2] += e;
/// 再做两次累加还原原数组

#include "cstdio"
#include <vector>
int main() {
  int N, M;
  scanf("%d %d", &N, &M);

  int l, r;
  /// 注意数据范围,没用long会通不过OJ,而且洛谷也不告诉你为什么通不过
  long s, e;
  std::vector<long> ans(N + 3, 0);
  while (M--) {
    scanf("%d %d %ld %ld", &l, &r, &s, &e);
    long d = (e - s) / (r - l);
    ans[l] += s;
    ans[l + 1] += d - s;
    ans[r + 1] += -e - d;
    ans[r + 2] += e;
  }

  for (int i = 1; i < N + 3; ++i) {
    ans[i] += ans[i - 1];
  }
  long _max = 0, _ans = 0;
  for (int i = 1; i < N + 3; ++i) {
    ans[i] += ans[i - 1];
    _max = _max > ans[i] ? _max : ans[i];
    _ans ^= ans[i];
  }

  printf("%ld %ld\n", _ans, _max);
}