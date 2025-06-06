/*
 * @lc app=leetcode.cn id=906 lang=cpp
 *
 * [906] 超级回文数
 * 数据量l,r \in [1, 1e18]
 * 一般CPP 1s能运行的复杂度在1e7 ~ 1e8
 * 根据数据量猜解法：
 * 1. 先开个根号：只需要遍历x in [l, \sqrt(r)],if isPalindrome(x) && x*x <=r && isPalindrome(x * x) -> x*x是超级回文数
 * 但复杂度为1e9,仍然有优化空间
 * 2. 回文数不需要遍历去寻找，可以去构造回文数：遍历y in [l, half(\sqrt(r))],拿y去构造x
 * 例如l = 1, \sqrt(r) = 123456, for y in [1, 123]: x = palindrome(y) = {(1,11), (2,22), ... (12321, 123321)}
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
        long l = std::stol(left);
        long r = std::stol(right);
        long sqrt_r = static_cast<long>(std::sqrt(r));

        long num = l;
        int cnt = 0;
        long x = 0;
        do{
            x = oddPalindrome(num);
            if(isPalindrome(x) && x*x <= r &&  isPalindrome(x*x)){
                ++cnt;
            }

            x = evenPalindrome(num);
            if(isPalindrome(x) && x*x <= r && isPalindrome(x*x)){
                ++cnt;
            }

            ++num;

        }while(x <= sqrt_r);


        return cnt;
    }

    //返回用x拼成的偶数位的回文数
    long evenPalindrome(long x){
        long res = x;
        while(x > 0){
            res =  res * 10 + x % 10;
            x /= 10;
        }

        return res;
    }

    long oddPalindrome(long x){
        long res = x / 10;
        while(x > 0){
            res = res * 10 + x % 10;
            x /= 10;
        }

        return res;
    }

    bool isPalindrome(long x){
        long offset = 1;
        long _x = x;

        while(_x / 10 > 0){
            offset *= 10;
            _x /= 10;
        }
        // offset = 10 ^ (len(x) -1), eg. x = 6234, offset = 1000

        do{
            int highest = x / offset;
            int lowest  = x % offset;
            
            if(highest != lowest){
                return false;
            }

            x /= offset;
            offset /= 10;
            x %= offset;
        }while(x > 0);

        return true;

    }
};
// @lc code=end

int main(){
    Solution s;

    std::string left = "4", right = "1000";
    std::cout << s.superpalindromesInRange(left, right);
}