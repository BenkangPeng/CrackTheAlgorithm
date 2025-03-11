
// 数组中只有1种数出现次数少于m次，其他数都出现了m次
// 返回出现次数小于m次的那种数
// 测试链接 : https://leetcode.cn/problems/single-number-ii/
// 注意 : 测试题目只是通用方法的一个特例，课上讲了更通用的情况


#include<vector>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int cnt[32] = {0};
        for(auto it : nums){
            for(int i = 0 ; i < 32 ; i++){
                if((it >> i) & 1){
                    cnt[i]++;
                }
            }
        }

        int ans = 0;
        for(int i = 0 ; i < 32 ; i++) {
            if(cnt[i] % 3){
                ans |= (1 << i);
            }
        }

        return ans;
    }
};