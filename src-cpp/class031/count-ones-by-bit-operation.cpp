// https://leetcode.cn/problems/hamming-distance/

class Solution {
private:
    int count_ones(int n){
        int ans = 0;
        for(int i = 0 ; i < 32 ; i++){
            if((n >> i) & 1){
                ans++;
            }
        }

        return ans;
    }
public:
    int hammingDistance(int x, int y) {
        return count_ones(x ^ y);
    }
};


//骚操作解法，用文字讲不清了，去看视频吧： 
//【算法讲解031【必备】位运算的骚操作】 【精准空降到 43:03】 https://www.bilibili.com/video/BV1ch4y1Q7vd/?share_source=copy_web&vd_source=dafafdec1805b35b4a99583c19bd6bbf&t=2583
int count_ones(int n){
    n = (n & 0x55555555) + ((n >> 1) & 0x55555555);
    n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
    n = (n & 0x0f0f0f0f) + ((n >> 4) & 0x0f0f0f0f);
    n = (n & 0x00ff00ff) + ((n >> 8) & 0x00ff00ff);
    n = (n & 0x0000ffff) + ((n >> 16) & 0x0000ffff);
    return n;
}