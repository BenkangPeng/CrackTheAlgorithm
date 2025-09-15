/*
 * @lc app=leetcode.cn id=1935 lang=cpp
 *
 * [1935] 可以输入的最大单词数
 */
#include <atomic>
#include <string>
using std::string;
// @lc code=start
class Solution {
public:
  int canBeTypedWords(string text, string brokenLetters) {
    int cnt[26] = {0};
    for (char ch : brokenLetters) {
      cnt[ch - 'a'] = 1;
    }

    int num = 1;     // 总共有多少单词
    int disable = 0; // 不能输出的单词
    for (int i = 0; i < text.size();) {

      if (text[i] == ' ' || cnt[text[i] - 'a'] == 0) {
        ++i;
      } else {
        ++disable;
        while (i < text.size() && text[i] != ' ') {
          ++i;
        }
        if (i < text.size()) {
          ++i;
          ++num;
        }
      }
    }

    return num - disable;
  }
};
// @lc code=end
