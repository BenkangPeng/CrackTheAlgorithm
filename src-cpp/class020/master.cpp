#include<vector>
class get_max_value{

public:
    int get_max(const std::vector<int>& arr, int l , int r){
        if(l == r)  return arr[l];

        int mid = l + ((r-l) >> 1);

        int left_max = get_max(arr , l , mid);
        int right_max = get_max(arr , mid+1 , r);
        return left_max > right_max ? left_max : right_max ;
    }
};

//master 公式 T(n) = a * T(n/b) + O(n^c)
//如果 log(b,a) < c , 则复杂度为O(n^c)
//如果 log(b,a) > c , 则复杂度为O(n^log(b,a))
//如果 log(b,a) == c , 则复杂度为O(n^c * log(n))

//特例：T(n) = 2 * T(n/b) + O(n * log(n))
//复杂度：O(n * (logn)^2)

//注意master公式只能用于等规模递归问题