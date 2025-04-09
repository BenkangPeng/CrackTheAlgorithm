/*
 * @lc app=leetcode.cn id=726 lang=cpp
 *
 * [726] 原子的数量
 */
#include<string>
#include<map>
#include<cctype>
#include<iostream>
// @lc code=start
class Solution {
public:
    std::string countOfAtoms(std::string formula) {
        int i = 0;
        std::map<std::string, int> ans(f(formula, i));
        std::string res;
        for(auto elem: ans){
            res += elem.first;
            if(elem.second != 1){
                res += std::to_string(elem.second);
            }
        }
        return res;
    }

    std::map<std::string, int> f(const std::string& s, int& pos){

        std::map<std::string, int> ans;//times of every element
        std::map<std::string, int> pre;//嵌套递归中返回的元素次数map        
        int i = pos;
        int times = 0;
        std::string elem;

        while(i < s.size() && s[i] != ')'){
            //四种情况：大写字母，小写字母，左括号，数字


            if(s[i] >= 'A' && s[i] <= 'Z' || s[i] == '('){
                //遇到大写字母或左括号时，就意味着要“结算”
                //即，处理之前统计到的元素及其数量
                if(s[i] != '('){
                    //大写字母
                    fill(ans, elem, pre, times);
                    elem = s[i++];
                    times = 0;
                }
                else{
                    //左括号
                    fill(ans, elem, pre, times);
                    elem = "";
                    times = 0;
                    ++i;//eat `(`
                    pre = f(s, i);
                    ++i;//eat ')'
                }
            }
            else if(isdigit(s[i])){
                times = times * 10 + (s[i] - '0');
                ++i;
            }
            else{
                //小写字母
                elem += s[i++];
            }
            
        }

        fill(ans, elem, pre, times);
        pos = i;
        return ans;
    }

    /**
     * @brief 将之前统计到的元素次数，加到总表ans中去
     * @param ans: 统计元素的总表
     * @param pre: 递归一个嵌套(处理括号内的元素)时，返回的括号内的元素次数
     * @elem: 元素名称
     * @times: 元素次数
     */
    void fill(std::map<std::string, int>& ans, const std::string& elem,
                std::map<std::string, int>& pre, int times){

        //校正times: 若元素后跟着1，例如NaOH
        //那么统计到元素个数times = 0
        times = times == 0 ? 1 : times;
        if(elem != ""){
            ans[elem] += times;
        }
        else if(pre.size() != 0){
            for(auto item: pre){
                ans[item.first] += times * item.second;
            }
        }

    }
};
// @lc code=end

