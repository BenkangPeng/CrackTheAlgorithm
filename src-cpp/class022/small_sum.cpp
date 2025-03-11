//测试链接 https://www.nowcoder.com/practice/edfe05a1d45c4ea89101d936cac32469

// * 思考一个问题在大范围上的答案，是否等于，左部分的答案 + 右部分的答案 + 跨越左右产生的答案
// * 计算“跨越左右产生的答案”时，如果加上左、右各自有序这个设定，会不会获得计算的便利性
// * 如果以上两点都成立，那么该问题很可能被归并分治解决（话不说满，因为总有很毒的出题人）



//自己写对数器
#include<iostream>
#include<vector>
#include<ctime>
#include<array>
class Solution{
private:
    int help[100001];
    long merge(std::vector<int>& nums , int l , int mid , int r){
        //统计部分
        long sum = 0 , ans = 0;
        for(int i = l , j = mid + 1 ; j <= r ; j++){
            while(i <= mid && nums[i] <= nums[j]){
                sum += nums[i++];
            }
            ans += sum;
        }

        //排序部分
        int i = l , j = mid + 1;
        int k = l;
        while(i <= mid && j <= r){
            help[k++] = nums[i] <= nums[j] ? nums[i++] : nums[j++];

        }
        while(i <= mid) help[k++] = nums[i++];
        while(j <= r)   help[k++] = nums[j++];
        for(int i = l ; i <= r ; i++){
            nums[i] = help[i];
        }
        
        return ans;
    }

    std::vector<int> get_random_vec(int n){
        std::vector<int> arr(n);
        for(int i = 0 ; i < n ;i++){
            arr[i] = rand() % 20 - 10; 
        }

        return arr;
    }
public:
    long small_sum( std::vector<int>& nums , int l , int r){
        if(l == r)  return 0;
        int mid = (l + r) >> 1;
        return small_sum(nums , l , mid) + small_sum(nums , mid + 1 , r) + merge(nums ,l , mid , r);
    }

    long brute_force(const std::vector<int>& nums){
        int n = nums.size();
        long ans = 0;
        for(int i = 1 ; i < n ; i++){
            int cur = nums[i];
            for(int j = i - 1 ; j >= 0 ; --j){
                if(nums[j] <= cur)  ans += nums[j];
            }
        }

        return ans;
    }

    bool validator(int times){
        int n = 5;
        std::vector<int> arr;
        bool res = true;
        while(times--){
            arr = get_random_vec(n);

            std::vector<int> _arr(arr);
            long ans1 = small_sum(_arr , 0 , n-1);//small_sum会改变_arr
            long ans2 = brute_force(arr);

            for(auto it : arr)
                printf("%d " , it);
            printf("\nsmall_sum : %ld  brute_force : %ld\n" , ans1 , ans2);
            if(ans1 != ans2){
                printf("fail\n");
                res = false;
                break;
            }
        }

        return res;
    }
};

int main()
{
    srand(time(0));
    // int n;
    // std::cin >> n;
    // std::vector<int> nums(n);
    // for(int i = 0 ; i < n ; i++){
    //     scanf("%d" , &nums[i]);
    // }

    Solution s;
    s.validator(10);

    // Solution s;
    // std::vector<int> nums = {2 , 6 , -10 , 5 ,1};
    // std::cout << s.small_sum(nums , 0 , 4) << std::endl;
    // std::cout << s.brute_force(nums) << std::endl;

    return 0;
}