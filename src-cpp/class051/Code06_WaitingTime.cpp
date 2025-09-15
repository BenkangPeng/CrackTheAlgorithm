// 计算等位时间
// 给定一个数组arr长度为n，表示n个服务员，arr[i]表示服务员i每服务一个人的时间
// 给定一个正数m，表示你之前有m人正在排队，请问你需要等多久？
// 假设m远远大于n，比如n <= 10^3, m <= 10^9，该怎么做是最优解？
// 谷歌的面试，这个题连考了2个月
// 找不到测试链接，所以用对数器验证

#include <algorithm>
#include <queue>
#include <vector>

// 用于验证的方法
class Solution0 {
public:
  int waitingTime(const std::vector<int> &arr, int m) {
    // server.first表示服务员可以开始服务的时间，server.second表示服务员完成一次服务所需时间
    using _pair = std::pair<int, int>;

    /// 用小根堆来做
    struct compare {
      bool operator()(const _pair &a, const _pair &b) {
        return a.first > b.first;
      }
    };

    std::priority_queue<_pair, std::vector<_pair>, compare> minHeap;

    for (int server : arr) {
      minHeap.push({0, server});
    }

    while (m--) {
      auto tmp = minHeap.top();
      minHeap.pop();
      tmp.first += tmp.second;
      minHeap.push(tmp);
    }

    return minHeap.top().first;
  }
};

class Solution1 {
public:
  int waitingTime(const std::vector<int> &arr, int m) {
    int l = m / arr.size();
    int r = *std::min_element(arr.begin(), arr.end()) * m;

    int mid, ans;
    while (l <= r) {
      mid = l + ((r - l) >> 1);
      if (f(arr, mid) >= m) {
        r = mid - 1;
        ans = mid;
      } else {
        l = mid + 1;
      }
    }

    return ans;
  }

  /// 服务员们一起工作time，可以服务的人数(包含可以开始进入服务的人数)
  int f(const std::vector<int> &arr, int time) {
    int total = 0;
    for(int server: arr){
        total += time / server + 1;
    }

    return total;
  }
};
