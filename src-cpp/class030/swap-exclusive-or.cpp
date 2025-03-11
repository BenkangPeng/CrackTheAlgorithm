
#include<iostream>
void swap_exclusive_or(int& a , int& b){
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}


int main()
{
    int a = 1 , b = 2;
    swap_exclusive_or(a , b);
    std::cout << "a = " << a << " b = " << b << std::endl;
    //注意传入函数的两个数要有不同的内存位置，否则变量会被重置为0
    //例如 swap_exclusive_or(nums[1] , nums[1]); nums[1]会被置零
    //因此这种交换值的写法知道就好，不推荐(单片机编程里面见得多)
}