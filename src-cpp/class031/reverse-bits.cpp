// https://leetcode.cn/problems/reverse-bits/description/

#include<cstdint>
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        for(int i = 0 ; i < 32 ; i++){
            int bit = (n >> i) & 1;
            if(bit == 1){
                ans |= 1 << (31 - i);
            }
        }

        return ans;
    }
};



// 用位运算来做：
// 32位太长，以8位举例：abcdefgh
// 1. 先交换相邻两位，变成badcfehg
// 2. 再以两位为一组，交换相邻两组：dcbahgfe
// 3. 再以四位为一组，交换相邻两组: hgfedcba

//交换逻辑的实现：
// 1. abcdefgh & 10101010 = a0c0e0g0 ; abcdefgh & 01010101 = 0b0d0f0h
//     (a0c0e0g0 >> 1) | (0b0d0f0h << 1) = badcfehg
// 2. badcfehg & 11001100 = ba00fe00 ; badcfehg & 00110011 = 00dc00hg
//     (ba00fe00 >> 2) | (00dc00hg << 2) = dcbahgfe
// 3. dcbahgfe & 11110000 = dcba0000 ; dcbahgfe & 00001111 = 0000hgfe
//     (dcba0000 >> 4) | (0000hgfe << 4) = hgfedcba

//对于32位数，依次类推
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        n = (( n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
        n = (( n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
        n = (( n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
        n = (( n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
        n = (n >> 16) | (n << 16);

        return n;
    }
};
