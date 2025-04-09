// test https://leetcode.cn/problems/decode-string/description/

#include<string>
#include<iostream>
class Solution {
public:
    std::string decodeString(std::string s) {
        int i = 0;
        return f(s, i);
    }

    std::string f(std::string& s, int& pos){

        int i = pos;
        int t = 0;//times
        std::string str;

        while(i < s.size() && s[i] != ']'){
            if(isdigit(s[i])){
                t = t * 10 + (s[i++] - '0');
            }
            else if(s[i] == '['){
                std::string tmp = f(s, ++i);//++i eat `[`
                while(t--){
                    str += tmp;
                }
                t = 0;
            }
            else{//char
                str += s[i++];
            }
        }

        pos = i + 1;//eat `]`
        return str;
    }
};

int main(){
    std::string expr = "3[a]2[bc]";
    Solution s;
    std::cout << s.decodeString(expr) << std::endl ;
}