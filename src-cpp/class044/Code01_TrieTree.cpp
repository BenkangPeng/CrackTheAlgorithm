/// test link:
/// https://www.nowcoder.com/practice/7f8a8553ddbf4eaab749ec988726702b
#include <array>
#include <iostream>
#include <memory>
#include <string>

class TrieNode {

public:
  /// 用TrieNode之间的边表示字符char
  /// @param pass 加入word遍历TrieTree时是否经过该node
  /// @param end 加入word遍历TrieTree时是否在该node结束
  int pass = 0;
  int end = 0;
  /// if the word is just consistent of 26 English char, array with size of 26
  /// is enough.
  std::array<std::unique_ptr<TrieNode>, 26> next;
  //   std::unordered_map<char, std::unique_ptr<TrieNode>> next;
};

class TrieTree {

public:
  std::unique_ptr<TrieNode> root = std::make_unique<TrieNode>();

  void insert(const std::string &word) {
    TrieNode *ptr = root.get();
    ++(ptr->pass);

    for (auto ch : word) {
      int index = ch - 'a';
      if (!ptr->next[index]) {
        ptr->next[index] = std::make_unique<TrieNode>();
      }
      ptr = ptr->next[index].get();
      ++(ptr->pass);
    }

    ++(ptr->end);
  }

  void erase(const std::string &word) {
    if (countWords(word) > 0) {
      TrieNode *ptr = root.get();
      --ptr->pass;

      for (auto ch : word) {
        int idx = ch - 'a';
        if (--ptr->next[idx]->pass == 0) {
          ptr->next[idx] = nullptr;
          return;
        }
        ptr = ptr->next[idx].get();
      }
      --ptr->end;
    }
  }

  bool search(const std::string &word) { return countWords(word) > 0; }

  /// return the number of `string`
  int numOfPrefix(const std::string &prefix) {
    auto ptr = root.get();

    for (auto ch : prefix) {
      TrieNode *next = ptr->next[ch - 'a'].get();
      if (next == nullptr) {
        return 0;
      }

      ptr = next;
    }

    return ptr->pass;
  }

  int countWords(const std::string &word) {
    auto ptr = root.get();
    for (auto ch : word) {
      auto next = ptr->next[ch - 'a'].get();
      if (!next) {
        return 0;
      }
      ptr = next;
    }

    return ptr->end;
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
int main() { test(); }