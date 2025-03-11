// https://leetcode.cn/problems/power-of-two/description/
//判断一个数是否为2的幂
//2的幂二进制形式诸如：0001 ， 0010 ， 0100等
// 即满足 n == lower_bit(n)
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n ==  n > 0 && (n & (-n));
    }
};