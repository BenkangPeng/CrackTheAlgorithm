/*
 * @lc app=leetcode.cn id=878 lang=cpp
 *
 * [878] 第 N 个神奇数字
 */
#include<algorithm>
// @lc code=start
class Solution {
private:
    //最大公因数
    int gcd(int a, int b){
        return b == 0 ? a : gcd(b, a%b);
    }

    //最小公倍数
    int lcm(int a, int b){
        return a / gcd(a,b) * b;
    }
public:
    int nthMagicalNumber(int n, int a, int b) {
        //这种找满足条件的第n个数的问题可以想办法用二分解决
        //复杂度从O(N) -> O(logN)

        long l = 1;
        long r = static_cast<long>(std::min(a, b)) * n;
        // [l,r]中至少有n个神奇的数，这就是本题的搜索空间
        long mid = 0;
        long ans;
        while(l <= r){
            mid = l + ((r-l)>>1);
            //如何计算[l,mid]中有多少个神奇的数？
            //mid/a + mid/b - mid/lcm(a,b)
            //a的神奇数 + b的神奇数 - a,b共有的神奇数

            if(mid/a + mid/b - mid/lcm(a,b) >= n){
                ans = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }

        return ans % static_cast<int>(1e9 + 7);
    }
};
// @lc code=end

