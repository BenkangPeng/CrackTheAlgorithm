/*
 * @lc app=leetcode.cn id=906 lang=cpp
 *
 * [906] 超级回文数
 * 数据量l,r \in [1, 1e18]
 * 一般CPP 1s能运行的复杂度在1e7 ~ 1e8
 * 根据数据量猜解法：
 * 1. 先开个根号：只需要遍历x in [l, \sqrt(r)],if isPalindrome(x) && x*x <=r && isPalindrome(x * x) -> x*x是超级回文数
 * 但复杂度为1e9,仍然有优化空间
 * 2. 回文数不需要遍历去寻找，可以去构造回文数：遍历y in [1, half(\sqrt(r))],拿y去构造x
 * 例如l = 100, \sqrt(r) = 123456, for y in [1, 123]: x = palindrome(y) = {(1,11), (2,22), ... (12321, 123321)}
 * 注意，对于一个y,能构造的回文数x有两个，例如palindrome(123) = 12321, 123321
 * 复杂度为1e5
 */
#include<string>
#include<cmath>
#include<iostream>
using std::string;
// @lc code=start
class Solution {
public:
    int superpalindromesInRange(string left, string right) {
        unsigned long long l = stoull(left);
        unsigned long long r = stoull(right);
        unsigned long long sqrt_r = static_cast<unsigned long long>(std::sqrt(r));

        unsigned long long num = 1;
        int cnt = 0;
        unsigned long long x = 0;
        do{

            x = evenPalindrome(num);
            if(check(x*x, l, r)){
                ++cnt;
            }

            x = oddPalindrome(num);
            if(check(x*x, l, r)){
                ++cnt;
            }

            ++num;

        }while(x <= sqrt_r);


        return cnt;
    }

    //返回用x拼成的偶数位的回文数
    unsigned long long evenPalindrome(unsigned long long x){
        unsigned long long res = x;
        while(x > 0){
            res =  res * 10 + x % 10;
            x /= 10;
        }

        return res;
    }

    unsigned long long oddPalindrome(unsigned long long x){
        unsigned long long res = x / 10;
        while(x > 0){
            res = res * 10 + x % 10;
            x /= 10;
        }

        return res;
    }

    bool isPalindrome(unsigned long long x){
        unsigned long long offset = 1;
        unsigned long long _x = x;

        while(_x / 10 > 0){
            offset *= 10;
            _x /= 10;
        }
        // offset = 10 ^ (len(x) -1), eg. x = 6234, offset = 1000

        while(x != 0){
            if(x / offset != x % 10){
                return false;
            }

            x %= offset;
            x /= 10;
            offset /= 100;
        }

        return true;

    }

    bool check(unsigned long long x, long l, long r){
        if(x >= l && x <= r && isPalindrome(x)){
            return true;
        }

        return false;
    }
};
// @lc code=end

int main(){
    Solution s;

    std::string left = "38455498359", right = "999999999999999999";
    std::cout << s.superpalindromesInRange(left, right);
}