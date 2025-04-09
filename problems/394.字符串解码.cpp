/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 */
#include<string>
#include<cctype>
using std::string;
// @lc code=start
class Solution {
private:
    int where = 0;
    
public:
    string decodeString(string s) {
        return f(s, 0);
    }

    std::string f(const std::string str, int idx){
        int cnt = 0, i = idx;
        int len = str.size();
        std::string path;
        
        while(i < len && str[i] != ']'){
            if(isalpha(str[i])){
                path += str[i++];
            }
            else if(isdigit(str[i])){
                cnt = cnt * 10 + (str[i++] - '0');
            }
            else{// [ 左括号
                path += repeat(cnt, f(str, i+1));
                cnt = 0;
                i = where + 1;
            }

        }
        where = i;

        return path;
    }

    std::string repeat(int cnt, const std::string& str){
        std::string ret;
        for(int i = 0; i < cnt; ++i){
            ret += str;
        }

        return ret;
    }
};
// @lc code=end

