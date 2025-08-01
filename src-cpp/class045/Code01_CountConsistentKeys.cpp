/// https://www.nowcoder.com/practice/c552d3b4dfda49ccb883a6371d9a6932
#include <iostream>
#include <memory>
#include <unordered_map>
#include <vector>

using std::vector;
struct TrieNode {
  int pass = 0;
  int end = 0;
  std::unordered_map<int, std::unique_ptr<TrieNode>> next;
};
class TrieTree {
private:
  /// 记得初始化root结点(给root分配空间)
  std::unique_ptr<TrieNode> root = std::make_unique<TrieNode>();
  int cnt = 0;

public:
  void insert(const std::vector<int> &diff) {
    TrieNode *node = root.get();
    for (int num : diff) {
      if (node->next.count(num) == 0) {
        node->next[num] = std::make_unique<TrieNode>();
      }
      node = node->next[num].get();
      ++node->pass;
    }
    ++node->end;
  }

  int numOfPrefix(const std::vector<int> &prefix) {
    TrieNode *node = root.get();
    for (int num : prefix) {
      if (node->next.count(num) == 0) {
        return 0;
      }
      node = node->next[num].get();
    }
    return node->pass;
  }
};
class Solution {
public:
  /**
   * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
   *
   *
   * @param b int整型vector<vector<>>
   * @param a int整型vector<vector<>>
   * @return int整型vector
   */
  vector<int> countConsistentKeys(vector<vector<int>> &b,
                                  vector<vector<int>> &a) {
    // write code here
    TrieTree tree;
    for (auto row : a) {
      /// a一行的差分值
      std::vector<int> diff;
      for (int i = 1; i < row.size(); ++i) {
        diff.push_back(row[i] - row[i - 1]);
      }
      tree.insert(diff);
    }

    std::vector<int> res;
    for (auto row : b) {
      /// b一行的差分值
      std::vector<int> diff;
      for (int i = 1; i < row.size(); ++i) {
        diff.push_back(row[i] - row[i - 1]);
      }
      res.push_back(tree.numOfPrefix(diff));
    }

    return res;
  }
};

// int main() {
//   std::vector<std::vector<int>> b = {
//       {1, 2, 3, 4, 5}, {2, 4, 6, 8}, {1, 4, 7, 10}};

//   std::vector<std::vector<int>> a = {
//       {3, 4, 5, 6, 7, 8}, {2, 4, 6, 8}, {1, 3, 5, 7, 9}};

//   Solution ss;
//   auto res = ss.countConsistentKeys(b, a);
//   for (auto elem : res) {
//     std::cout << elem << " ";
//   }
// };
