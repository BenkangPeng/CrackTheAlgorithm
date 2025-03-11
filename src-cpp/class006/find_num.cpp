#include<iostream>
#include<vector>
#include<ctime>
#include<algorithm>
class binary_search{
    public:
        int find_num(const std::vector<int>& sorted_arr , int num){
            int len = sorted_arr.size();
            if(len == 0)    return -1;

            int l = 0 , r = len - 1;

            while(l <= r){
                int mid = l + ((r-l) >> 1);

                if(sorted_arr[mid] == num){
                    return mid;
                }
                else if(sorted_arr[mid] > num){
                    r = mid - 1;
                }
                else l = mid + 1;
            }

            return -1;
        }


        int brute_force(const std::vector<int>& sorted_arr , int num){
            int len = sorted_arr.size();
            if(len == 0)    return -1;
            for(int i = 0 ; i < len ; i++){
                if(sorted_arr[i] == num)   return i;
            }

            return -1;
        }


        std::vector<int> random_arr(int len){
            std::vector<int> arr(len , 0);
            for(int i = 0 ; i < len ; i++){
                arr[i] = rand() % 100 - 50;
            }

            std::sort(arr.begin() , arr.end());
            auto last = std::unique(arr.begin() , arr.end());
            arr.erase(last , arr.end());
            return arr;
        }

        void validator(int times){
            bool pass = true;
            while(times--){
                int len = rand() % 100;
                std::vector<int> arr = random_arr(len);

                int num = arr[rand() % len + (len/2)];
                int idx1 = find_num(arr , num);
                int idx2 = brute_force(arr , num);                
                if(idx1 != idx2){
                    std::cout << "error : find_num = " << idx1 << "  brute_force = " << idx2 << std::endl;
                    pass = false;

                    std::cout << "num = " << num << std::endl;
                    for(auto it : arr)
                        std::cout << it << " ";
                    break;
                }
            }

            if(pass)    std::cout << "pass~" << std::endl;
        }

};
int main()
{
    srand(time(nullptr));

    binary_search s;
    s.validator(100);
    // std::vector<int> arr = {1 , 3 , 5 , 7 , 9};
    // std::cout << s.find_num(arr , 7);
}