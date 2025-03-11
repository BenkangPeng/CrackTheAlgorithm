//用多种思路完成一个题目（暴力一个，最优解一个）
//对数器就是随机生成一些测试用例
//分别喂给暴力算法和最优算法
//比对两个解法的输出，判断结果是否一致
//例如第四课中三个排序算法


#include<iostream>
#include<vector>
#include<random>
#include<ctime>
class sort_{

    private:
        void swap(int& a , int& b){
            int temp = a;
            a = b;
            b = temp;
        }
    public:
        template <typename T>
        std::vector<T> select_sort(const std::vector<T>& arr){
            int len = arr.size();
            if(len < 2) return arr;

            std::vector<T> _arr(arr);            

            for(int i = 0 ; i < len ; i++){
                int min_idx = i;
                for(int j = i + 1 ; j < len ; j++){
                    if(_arr[min_idx] > _arr[j])   min_idx = j;
                }
                swap(_arr[i] , _arr[min_idx]);
            }

            return _arr;
        }

        template <typename T>
        std::vector<T> bubble_sort(const std::vector<T>& arr){
            int len = arr.size();
            if(len < 2) return arr;

            std::vector<T> _arr(arr);

            for(int end = len - 1 ; end > 0 ; end--){
                for(int i = 0 ; i < end ; i++){
                    if(_arr[i] > _arr[i+1]) swap(_arr[i] , _arr[i+1]);
                }
            }

            return _arr;
        }

        template <typename T>
        std::vector<T> insert_sort(const std::vector<T>& arr){
            int len = arr.size();
            if(len < 2) return arr;

            std::vector<T> _arr(arr);

            for(int i = 1 ; i < len ; i++){
                for(int j = i-1 ; j >= 0 ; j--){
                    if(_arr[j] > _arr[j+1]) swap(_arr[j] , _arr[j+1]);
                }
            }

            return _arr;
        }

        bool random_test(){
            srand(time(nullptr));
            std::vector<int> arr;
            for(int i = 0 ; i < 50 ; i++){
                arr.push_back(rand() % 200 - 100);
            }

            std::vector<int> arr1 = select_sort(arr);
            std::vector<int> arr2 = bubble_sort(arr);
            std::vector<int> arr3 = insert_sort(arr);


            if(arr1 == arr2 && arr2 == arr3){
                // std::cout << "pass~" << std::endl;
                return true;
            }
            else{
                // std::cout << "fail-" << std::endl;
                return false;
            }
        }

        template <typename T>
        void display_arr(const std::vector<T>& arr){
            for(auto it : arr){
                std::cout << it << " ";
            }
            std::cout << std::endl;
        }

};



int main()
{
    std::vector<int> arr = {5 , 3 ,4 , 2 ,-3, 33};
    sort_ s;
    std::vector<int> arr1 = s.select_sort(arr);
    std::vector<int> arr2 = s.bubble_sort(arr);
    std::vector<int> arr3 = s.insert_sort(arr);

    if(arr1 == arr2 && arr2 == arr3){
        std::cout << "pass~" << std::endl;
        s.display_arr(arr1);
    }
    else{
        std::cout << "fail-" << std::endl;
        std::cout << "error-info: " << std::endl;
        s.display_arr(arr1);
        s.display_arr(arr2);
        s.display_arr(arr3);
    }

    

    //random test
    int times = 20;
    while(times--){
        if(! s.random_test()){
            std::cout << "fail-" << std::endl;
            break;
        }
        else std::cout << "pass~" << std::endl;
    }
}