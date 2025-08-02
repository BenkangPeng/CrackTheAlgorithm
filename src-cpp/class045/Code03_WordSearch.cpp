/// https://leetcode.cn/problems/word-search-ii/
/*!
@note 将words中word存在字典树中,注:`end`改进为存储完整的word,以便取出word
遍历board[i][j],从每单个字符出发,递归拼凑字符串,并在字典树中进行查找
 */
#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;
const int MAXN = (int)1e4;
struct TrieNode {
  int pass = 0;
  /// 若word在当前node结尾,该node存储该word的值
  std::string end = "";
  int next[26] = {0};
};

class TrieTree {
public:
  TrieNode nodes[MAXN];
  int cnt = 0;

  void insert(const std::vector<std::string> &words) {
    /// current node
    int cur = 0;
    int idx = 0;
    for (auto word : words) {
      cur = 0; /// 一定要记得插入新单词时重置cur
      for (auto ch : word) {
        idx = ch - 'a';
        if (nodes[cur].next[idx] == 0) {
          nodes[cur].next[idx] = ++cnt;
        }
        cur = nodes[cur].next[idx];
        ++nodes[cur].pass;
      }
      nodes[cur].end = word;
    }
  }
};
class Solution {
private:
  TrieTree tree;

public:
  vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
    tree.insert(words);

    int row = board.size();
    int col = board[0].size();
    vector<string> ans;
    for (int i = 0; i < row; ++i) {
      for (int j = 0; j < col; ++j) {
        f(board, i, j, 0, ans);
      }
    }

    return ans;
  }

private:
  /**
  @param cnt 现在到达的TreeNode的编号
  @return 从board[i][j]出发找到的word的个数
  */
  int f(vector<vector<char>> &board, int i, int j, int cnt,
        vector<string> &ans) {
    /// 索引越界 or board[i][j]被访问过(标记为'0')
    if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() ||
        board[i][j] == '0') {
      return 0;
    }
    char ch = board[i][j];
    int idx = ch - 'a';
    int next_node = tree.nodes[cnt].next[idx];
    /// cnt node之后没有字符ch的路 or 字符ch的路(结点)的pass为0(被剪枝,看后面)
    if (next_node == 0 || tree.nodes[next_node].pass == 0) {
      return 0;
    }

    /// 记录current node(cnt)向四周递归搜索后,能获得的word个数
    int numOfWord = 0;
    /// 当前node的`end`
    string end_str = tree.nodes[next_node].end;
    /// next_node是某字符串的结尾node
    if (!end_str.empty()) {
      ++numOfWord;
      ans.push_back(end_str);
      /// 清空next_node的end,避免往ans中添加重复word
      tree.nodes[next_node].end.clear();
    }

    /// 将已经到达过的字符标记成0,避免重复访问
    board[i][j] = '0';

    /// board[i][j]上下左右递归搜索
    numOfWord += f(board, i - 1, j, next_node, ans);
    numOfWord += f(board, i + 1, j, next_node, ans);
    numOfWord += f(board, i, j - 1, next_node, ans);
    numOfWord += f(board, i, j + 1, next_node, ans);

    /// 恢复字符
    board[i][j] = ch;

    /// 当前node.pass -= numOfWord
    /// 例如, 在构建字典树后,node1.pass=2, 基于node1搜索后找到2个matching
    /// word(numOfWord) 这时, 可以pass -=
    /// numOfWord标记pass=0,表明node1以下的nodes构成的word已经找过了,不需要再找了
    tree.nodes[next_node].pass -= numOfWord;

    return numOfWord;
  }
};

// int main() {
//   Solution ss;
//   vector<vector<char>> board = {{'o', 'a', 'a', 'n'},
//                                 {'e', 't', 'a', 'e'},
//                                 {'i', 'h', 'k', 'r'},
//                                 {'i', 'f', 'l', 'v'}};

//   vector<std::string> words = {"oath", "pea", "eat", "rain"};
//   auto ans = ss.findWords(board, words);
//   for (auto elem : ans) {
//     std::cout << elem << std::endl;
//   }
// }
