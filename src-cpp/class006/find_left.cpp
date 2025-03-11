#include<iostream>
#include<ctime>
#include<vector>
#include<algorithm>
class solution{

    public:
        int find_left(const std::vector<int>& sorted_arr , int num){
            //找到>=num的第一个位置
            int len = sorted_arr.size();
            if(len == 0)    return -1;

            int l = 0 , r = len - 1;
            int ans = -1;
            while(l <= r){
                int mid = l + ((r-l) >> 1);

                if(sorted_arr[mid] >= num){
                    ans = mid;
                    r = mid - 1;//一定是mid-1,如果写成r = mid;会进入死循环
                }
                else l = mid + 1;

            }

            return ans;
        }

        int brute_force(const std::vector<int>& sorted_arr , int num){
            int len = sorted_arr.size();
            if(len == 0)    return -1;
            for(int i = 0 ; i < len ; i++){
                if(sorted_arr[i] >= num)   return i;
            }

            return -1;
        }

        std::vector<int> random_arr(int len){
            std::vector<int> arr(len , 0);
            for(int i = 0 ; i < len ; i++){
                arr[i] = rand() % 100 - 50;
            }

            std::sort(arr.begin() , arr.end());
            return arr;
        }

        void validator(){
            
            int len = rand() % 100;
            std::vector<int> arr = random_arr(len);

            int num = arr[rand() % len + (len/2)];
            int idx1 = find_left(arr , num);
            int idx2 = brute_force(arr , num);                
            if(idx1 != idx2){
                std::cout << "error : find_num = " << idx1 << "  brute_force = " << idx2 << std::endl;
                std::cout << "num = " << num << std::endl;
                for(auto it : arr)
                    std::cout << it << " ";
            }
            // else std::cout << "pass~" << std::endl;
            
        }
};

int main()
{
    srand(time(nullptr));
    solution s;
    // std::vector<int> arr = {1 , 2 , 2 , 3 , 3 ,4 ,5};
    // std::cout << s.find_left(arr , 3) << std::endl;
    int times = 100;
    while(times--){
        s.validator();
    }
}