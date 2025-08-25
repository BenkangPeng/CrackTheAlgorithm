/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */
#include <string>
#include <vector>

using std::string;
using std::vector;
// @lc code=start
class Solution {
public:
  bool exist(vector<vector<char>> &board, string word) {
    int m = board.size(), n = board[0].size();
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (f(board, i, j, word, 0)) {
          return true;
        }
      }
    }

    return false;
  }

private:
  /// 从board[i][j]走起, 能否凑出word[k:]
  bool f(vector<vector<char>> &board, int i, int j, string &word, int k) {
    /// base case
    if (k == word.size()) {
      return true;
    }

    int m = board.size(), n = board[0].size();
    if (i < 0 || i == m || j < 0 || j == n || board[i][j] != word[k]) {
      return false;
    }

    char tmp = board[i][j];
    board[i][j] = '0';

    ++k;
    bool ans = f(board, i + 1, j, word, k) || f(board, i - 1, j, word, k) ||
               f(board, i, j + 1, word, k) || f(board, i, j - 1, word, k);
    board[i][j] = tmp;

    return ans;
  }
};
// @lc code=end