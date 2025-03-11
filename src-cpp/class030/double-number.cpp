// https://leetcode.cn/problems/single-number-iii/description/

#include<vector>
#include<climits>
using namespace std;
class Solution {
private:
    inline int low_bit(int n){
        return n & (-n);
    }
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xor_all = 0;
        for(auto it : nums){
            xor_all ^= it;

        }

        int low_1 = xor_all != INT_MIN ? low_bit(xor_all) : INT_MIN;
        //leetcode上有个老六测试用例：[1,1,0,-2147483648]
        //整个数组异或下来xor_all = INT_MIN , 传入low_bit函数后(-INT_MIN)溢出了  (INT_MAX = -INT_MIN - 1)
        //因此做一个特判，INT_MIN的low_bit就是其本身


        //在low_1这一bit上，a,b(要求的数)中一定有一个为1，一个为0
        //假设a的low_1位为1，b的为0

        int xor_low_1 = 0;
        for(auto it : nums){
            if((it & low_1) == 0){
                xor_low_1 ^= it;//只异或上low_1为0的数，则xor_low_1 = a;
            }
        }

        return {xor_low_1 , xor_all ^ xor_low_1};


    }
};