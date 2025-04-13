// 有装下8个苹果的袋子、装下6个苹果的袋子，一定要保证买苹果时所有使用的袋子都装满
// 对于无法装满所有袋子的方案不予考虑，给定n个苹果，返回至少要多少个袋子
// 如果不存在每个袋子都装满的方案返回-1

//抽象递归,递归真的牛
#include<iostream>
#include<climits>
int f(int n){
    if(n < 0){
        return -1;//表示无法找到方案将每个袋子都装满
    }
    
    if(n == 0){
        return 0;//之前用的袋子已经转满且已把苹果装完，不需要新的袋子
    }


    int bag6 = f(n-6);//先拿一个容量为6的袋子装一袋，再递归装剩下的n-6个苹果
    int bag8 = f(n-8);
    bag6 = (bag6 != -1/*剩下的n-6个苹果装好了*/) ? bag6 + 1 : -1;
    bag8 = (bag8 != -1) ? bag8 + 1 : -1;
    
    if(bag6 != -1 && bag8 != -1){
        return std::min(bag6, bag8);
    }
    else{
        return std::max(bag6, bag8);
    }
}
int main(){

    //打表找规律
    // for(int i = 1; i < 100; ++i){
    //     int res = f(i);
    //     if(res != -1){
    //         std::cout << i << "    " << res << std::endl;
    //     }
    // }

    //于是有了方法二
    auto f2 = [](int n){
        if(n & 1 != 0){
            //奇数肯定不能
            return -1;
        }

        if(n < 18){
            if(n == 6 || n == 8){
                return 1;
            }

            if(n == 12 || n ==14 || n == 16){
                return 2;
            }
            return -1;
        }
        else    return (n - 18) / 8 + 3;
    };

    std::cout << f2(98) << std::endl;
  

    return 0;
}