// 草一共有n的重量，两只牛轮流吃草，A牛先吃，B牛后吃
// 每只牛在自己的回合，吃草的重量必须是4的幂，1、4、16、64....
// 谁在自己的回合正好把草吃完谁赢
// 根据输入的n，返回谁赢


#include<iostream>
#include<string>


std::string f(int n, std::string cur){
    std::string enemy = cur == "A" ? "B": "A";

    if(n < 5){
        if(n == 1 || n == 3 || n == 4){
            return cur;
        }
        else{
            return enemy;
        }
    }

    int eat = 1;//吃一份草
    while(eat <= n){
        if(f(n - eat, enemy) == cur){
            return cur;
        }
        eat *= 4;
    }

    return enemy;
}

int main(){
    //打表找规律
    for(int i = 0; i < 100; ++i){
        std::cout << "i = " << i << "  Win:      " << f(i, "A") << std::endl;
    }

    auto f2 = [](int n, std::string cur){
        std::string enemy = cur == "A"? "B" : "A";
        if (n % 5 == 0 || n % 5 == 2) {
			return enemy;
		}
        else{
			return cur;
		}
    };
}