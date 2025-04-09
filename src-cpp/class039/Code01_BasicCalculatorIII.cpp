#include<string>
#include<vector>
#include<iostream>

class BasicCalculatorIII{
public:

    int compute(std::vector<int>& nums, std::vector<char>& ops){
        int res = nums[0];
        for(int i = 1; i < nums.size(); ++i){
            ops[i-1] == '+' ? res += nums[i] : res -= nums[i];
        }

        return res;
    }

    void push(std::vector<int>& nums, std::vector<char>& ops, int cur, char op){
        if(ops.empty() || ops.back() == '+' || ops.back() == '-'){
            nums.push_back(cur);
            ops.push_back(op);
        }
        else{//ops.back() is '*' or '/', we should to calculate the mulitply or divide
            (ops.back() == '*') ? nums.back() *= cur : nums.back() /= cur;
            ops.back() = op;
        }
    }

    int evaluate(std::string& s, int& pos){
        std::vector<int> nums;
        std::vector<char> ops;
        int i = pos, cur = 0;

        while(i < s.size() && s[i] != ')'){
            if(isdigit(s[i])){ //convert char into the number
                cur = cur * 10 + (s[i++] - '0');
            }
            else if(s[i] == '('){//if meet the `(`, handle the nested recursion
                cur = evaluate(s, ++i);//++i eat the `(`
                ++i;// eat the `)`
                
            }
            else{//meet the operator +-*/
                push(nums, ops, cur, s[i++]);
                cur = 0;
            }
        }
        // push the last number
        push(nums, ops, cur, '+');
        pos = i;
        return compute(nums, ops);
    }
    
    int calculate(std::string& expr){
        // move all the spaces
        std::string expr_;
        for(char c : expr){
            if(c != ' ')    expr_ += c;
        }

        int i = 0;
        return evaluate(expr_, i);
    }
};

void validation(){
    std::vector<std::pair<std::string, int>> testcases = {
    // 基础运算
    {"1+1", 2},
    {"6-4", 2},
    {"3 * 4", 12},
    {"12/3", 4},
    
    // 优先级测试
    {"3+5 * 2", 13},      // 3+(5 * 2)=13
    {"(3+5)*2", 16},     // 8 * 2=16
    {"10-4/2", 8},       // 10-2=8
    
    // 括号嵌套
    {"((2+3)*4)", 20},           // 5 * 4=20
    {"(1+(4*(6-2)))", 17},       // 1+(4 * 4)=17
    {"((15/(7-2))-1)", 2},       // (15/5)-1=2
    
    // 边界值
    {"0", 0},                    // 单个0
    {"2147483647", 2147483647},  // 最大int值
    {"1-2147483647", -2147483646}, // 整数下界
    
    // 特殊运算符情况
    {"3 + 2 * 2 - 4 / 2", 5},    // 3+4-2=5
    {"1+2 * 3/6", 2},              // 1+(6/6)=2
    {"2 * 3 * 4/8", 3},              // (6 * 4)/8=3
    
    // 连续运算符（需注意程序是否支持）
    // {"3++4", 7},                 // 3+0+4=7（程序当前逻辑）
    // {"5--2", 3},                 // 5-0-2=3（程序当前逻辑）
    
    // 除零保护（需程序额外处理）
    // {"4/0", ERROR},           // 运行时错误（当前未处理）
    
    // 空格处理
    {" ( 3 + 5 )  * 2 ", 16},    // 带空格版 (3+5)*2
    
    // 复杂混合运算
    {"(2+3)*(4-1)", 15},         // 5 * 3=15
    {"10/(2+3)*4-6", 2},         // (10/5)*4-6=2
    {"2*(5+3*(8-2))/7", 6}       // 2*(5+18)/7=2 * 23/7≈6（但整数除法 46/7=6）
    };

    BasicCalculatorIII cal;
    for(auto item: testcases){
        if(cal.calculate(item.first) != item.second){
            std::cout << "the testcase " << item.first << " is error" << std::endl;
            std::cout << "expect: " << item.second << " actual: " << cal.calculate(item.first) << std::endl;
            return;
        }
    }
    std::cout << "All pass~" << std::endl;
}

int main(){
    BasicCalculatorIII cal;
    std::string expr = "(1+(4*(6-2)))";
    std::cout << cal.calculate(expr) << std::endl;

    validation();

    return 0;
}