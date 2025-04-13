
// 判断一个数字是否是若干数量(数量>1)的连续正整数的和
#include<iostream>
bool f(int n){
    if(n == 1)  return false;

    if(n % 2 == 1){
        //奇数一定能
        //例如奇数M = 2n + 1, n = 1,2...
        //那么M = n + (n +1)
        return true;
    }

    //偶数
    int l = 1, r = n / 2;

    for(int i = l; i <= r; ++i){
        int sum = 0;
        for(int k = i; k <= r; ++k){
            sum += k;
            if(sum == n){
                return true;
            }
            if(sum > n) break;
        }
    }

    return false;
}

int main(){
    for(int i = 0; i < 200; ++i){
        bool res = f(i);
        if(!res){
            std::cout << i << ":  " << res << std::endl;
        }
    }

    //规律找出来了，2^n的数，n=0,1,2....不能被连续的正整数相加表示
    //那么只需要检查最后1bit是否为1即可
    auto f2 = [](int n){
        return (n & (n-1)) != 0;
    };

    for(int i = 0; i < 200; ++i){
        bool res = f2(i);
        if(!res){
            std::cout << i << ":  " << res << std::endl;
        }
    }
}