// test site: https://www.nowcoder.com/practice/92e6247998294f2c933906fdedbc6e6a
#include<string>
#include<vector>
#include<unordered_set>

class Solution {
private:
    std::string path = "";
    std::unordered_set<std::string> ans;

    /**
     * imagine this problem as a binary tree recursive problem
     *      eg. s = "abc", the left branch indicates that head node is included, while the right is not.
     *      a
     *     / \
     *    b   b
     *   / \ / \
     *  c  c c c
     * /\ /\/\/\
     * 
     * "abc","ab","ac","a","bc","b","c",""
     * 
     * @param i: the level of binary tree
     */
    void f(const std::string& s, int i){
        if(i == s.size()){
            ans.insert(path);
        }
        else{
            path += s[i];
            f(s, i+1);
            path.pop_back();
            f(s,i+1);
        }
    }

public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param s string字符串 
     * @return string字符串vector
     */
    std::vector<std::string> generatePermutation(std::string s) {
        // write code here
        f(s,0);
        std::vector<std::string> res;
        for(const std::string& elem : ans){
            res.push_back(elem);
        }
        return res;
    }
};