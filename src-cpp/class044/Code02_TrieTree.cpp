/// https://www.nowcoder.com/practice/7f8a8553ddbf4eaab749ec988726702b

/// 静态数组的解法，，更快
#include <cassert>
#include <iostream>
#include <string>

const int MAXN = 100000;

class TrieTree {
private:
  int tree[MAXN][26] = {0};
  int pass[MAXN] = {0};
  int end[MAXN] = {0};
  int cnt = 0;

public:
  void insert(const std::string &word) {
    int node = 0;
    for (char ch : word) {
      int idx = ch - 'a';
      // 检查是否超出最大节点数
      if (cnt >= MAXN) {
        printf("cnt is out of MAXN\n");
        return;
      }

      if (tree[node][idx] == 0) {
        tree[node][idx] = ++cnt;
      }
      // 更新当前节点的pass
      pass[node]++;
      node = tree[node][idx];
    }
    // 更新最后一个节点的pass和end
    pass[node]++;
    end[node]++;
  }

  void erase(const std::string &word) {
    if (countWords(word) > 0) {
      int node = 0;
      int last_branch = 0;
      char last_char = 0;

      for (char ch : word) {
        int idx = ch - 'a';
        // 记录最后可能删除的分支
        if (pass[node] == 1) {
          last_branch = node;
          last_char = idx;
        }

        // 更新当前节点的pass并移动到子节点
        pass[node]--;
        node = tree[node][idx];
      }
      // 更新最后一个节点的pass和end
      pass[node]--;
      end[node]--;

      // 删除分支（如果pass变为0）
      if (last_branch != 0) {
        tree[last_branch][last_char] = 0;
      }
    }
  }

  int countWords(const std::string &word) {
    int node = 0;
    for (char ch : word) {
      int idx = ch - 'a';
      if (tree[node][idx] == 0) {
        return 0;
      }
      node = tree[node][idx];
    }
    return end[node];
  }

  int numOfPrefix(const std::string &prefix) {
    int node = 0;
    for (char ch : prefix) {
      int idx = ch - 'a';
      if (tree[node][idx] == 0) {
        return 0;
      }
      node = tree[node][idx];
    }
    return pass[node];
  }

  bool search(const std::string &word) { return countWords(word) > 0; }
};

void test() {
  int m; // times of query
  std::cin >> m;
  int op;
  std::string word;
  TrieTree tree;
  while (m--) {
    std::cin >> op >> word;
    switch (op) {
    case 1:
      tree.insert(word);
      break;
    case 2:
      tree.erase(word);
      break;
    case 3:
      if (tree.search(word)) {
        printf("YES\n");
      } else {
        printf("NO\n");
      }
      break;
    case 4:
      printf("%d\n", tree.numOfPrefix(word));
      break;
    }
  }
}
int main() { test(); }