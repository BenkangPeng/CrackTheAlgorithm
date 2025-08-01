/// https://www.nowcoder.com/practice/7f8a8553ddbf4eaab749ec988726702b

/// 静态数组的解法，，更快
#include <cassert>
#include <iostream>
#include <string>

const int MAXN = 100000;

struct TrieNode {
  int next[26] = {0};
  int pass = 0;
  int end = 0;
  void clear() {
    pass = 0;
    end = 0;
    for(int i = 0; i< 26; ++i){
        next[i] = 0;
    }
  }
};

class TrieTree {
private:
  TrieNode tree[MAXN];
  int cnt = 0; // 0号结点是root node

public:
  void insert(const std::string &word) {
    int idx;
    int node = 0;
    for (auto ch : word) {
      idx = ch - 'a';
      if (tree[node].next[idx] == 0) {
        assert(cnt < MAXN &&
               "`cnt` is bigger than `MAXN` now. Maybe need a bigger `MAXN`");
        tree[node].next[idx] = ++cnt;
      }
      node = tree[node].next[idx];
      ++tree[node].pass;
    }
    ++tree[node].end;
  }

  void erase(const std::string &word) {
    if (countWords(word) > 0) {
      int node = 0;
      int idx;
      for (auto ch : word) {
        idx = ch - 'a';
        node = tree[node].next[idx];
        --tree[node].pass;
      }
      --tree[node].end;
    }
  }

  int countWords(const std::string &word) {
    int idx;
    int node = 0;
    for (auto ch : word) {
      idx = ch - 'a';
      if (tree[node].next[idx] == 0) {
        return 0;
      }
      node = tree[node].next[idx];
    }
    return tree[node].end;
  }

  int numOfPrefix(const std::string &word) {
    int node = 0;
    int idx;
    for (auto ch : word) {
      idx = ch - 'a';
      if (tree[node].next[idx] == 0) {
        return 0;
      }
      node = tree[node].next[idx];
    }
    return tree[node].pass;
  }

  void clear() {
    for (int i = 0; i <= cnt; ++i) {
        tree[i].clear();
    }
  }
  bool search(const std::string& word){
    return countWords(word) > 0;
  }
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

/// 左神的写法，，但我感觉tree[MAXN][26]不太好理解
class TrieTree_ {
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
      int idx = 0;
      for (auto ch : word) {
        idx = ch - 'a';
        node = tree[node][idx]; // 先跳到下一个node，，再减pass[node]
        --pass[node];
      }
      --end[node];
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
  void clear() {
    for (int i = 0; i <= cnt; ++i) {
      pass[i] = 0;
      end[i] = 0;
      for (int j = 0; j < 26; ++j) {
        tree[i][j] = 0;
      }
    }
  }
};
int main() { test(); }