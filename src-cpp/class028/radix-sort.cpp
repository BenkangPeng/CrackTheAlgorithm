// 测试链接： https://leetcode.cn/problems/sort-an-array/
//基于非比较的排序：基数排序
// 打败99%
#include<vector>


class Solution {
private:
    const int MAXN = 50001;
    int* help = new int[MAXN];
    int BASE = 10;//进制
    int* cnt = new int[BASE];

    int bits(int x){//得出BASE进制下，一个数的位数
        int n = 0;
        while(x > 0){
            x /= BASE;
            n++;
        }

        return n;
    }
public:
    Solution(){
        for(int i = 0 ; i < BASE ; i++){
            cnt[i] = 0;
        }
    }

    void radix_sort(std::vector<int>& nums , int bits){
        int n = nums.size();
        for(int i = 0 , offset = 1 ; i < bits ; i++ , offset *= BASE){

            for(int j = 0 ; j < n ; j++){
                cnt[(nums[j] / offset) % BASE]++;
            }

            for(int j = 1 ; j < BASE ; j++){
                cnt[j] = cnt[j-1] + cnt[j];
            }

            for(int k = n - 1 ; k >= 0 ; k--){
                help[ --cnt[(nums[k]/offset)%BASE] ] = nums[k];
            }

            for(int k = 0 ; k < n ; k++){
                nums[k] = help[k];
            }
        }
    }
public:
    std::vector<int> sortArray(std::vector<int>& nums) {
        int min = nums[0];//找最小值
        for(auto it : nums){
            min = min < it ? min : it;
        }

        int max = nums[0] - min;
        for(auto& it : nums){
            it -= min;//减去最小值，使得nums中均为非负数，最后记得加回去
            max = max > it ? max : it;
        }

        radix_sort(nums , bits(max));

        for(auto& it : nums){
            it += min;
        }
        return nums;

    }

    ~Solution(){
        delete [] help;
        delete [] cnt;
    }
};