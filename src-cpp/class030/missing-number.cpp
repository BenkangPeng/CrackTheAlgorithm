// https://leetcode.cn/problems/missing-number/description/
// 由此题可以将异或运算理解成无进位加法
#include<vector>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int xor_all = 0 , xor_has = 0;
        for(int i = 0 ; i < n ; i++){
            xor_all ^= i;
            xor_has ^= nums[i];
        }
        xor_all ^= n;
        return xor_all ^ xor_has;
    }
};