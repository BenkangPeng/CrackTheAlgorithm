// https://leetcode.cn/problems/bitwise-and-of-numbers-range/description/

// 按位与有这样一个规律，当n和(n-1)做按位与时，效果可以视为将x的lowbit位置为0
//例如，0111 & 0110 = 0110
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        while(left < right){
            right -= (right & -right);
        }

        return right;
    }
};