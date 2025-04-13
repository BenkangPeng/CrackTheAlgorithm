// 可以用r、e、d三种字符拼接字符串，如果拼出来的字符串中
// 有且仅有1个长度>=2的回文子串，那么这个字符串定义为"好串"
// 返回长度为n的所有可能的字符串中，好串有多少个
// 结果对1000000007取模， 1 <= n <= 10^9
// 示例：
// n = 1, 输出0
// n = 2, 输出3
// n = 3, 输出18

#include<string>
#include<iostream>

bool check(std::string& str, int l, int r){
    while(l < r){
        if(str[l] != str[r]){
            return false;
        }
        ++l;
        --r;
    }

    return true;
}

int f(int n, int i, std::string& str){
    if(i == n-1){
        //字符串长度已经变成了n
        //遍历每一个子串判断是否为回文串
        int cnt = 0;
        for(int i = 0; i < n-1; ++i){
            for(int j = i+1; j < n; ++j){
                if(check(str, i, j)){
                    ++cnt;
                }
                if(cnt > 1){
                    return 0;//不是“好串”
                }
            }
        }

        return cnt == 0 ? 0: 1;
    }
    else{
        int ans = 0;
        str[i] = 'r';
        ans += f(n, i+1, str);
        str[i] = 'e';
        ans += f(n, i+1, str);
        str[i] = 'd';
        ans += f(n, i+1, str);

        return ans % 1000000007;
    }
}

int main(){
    int n = 10;
    

    //打表找规律
    for(int i = 1; i < 10; ++i){
        std::string str(i, ' ');
        std::cout << i << ":  " << f(i, 0, str) << std::endl;
    }

    auto f2 = [](int n){
        if(n == 1 || n == 2){
            return 0;
        }

        if(n == 3)  return 3;
        if(n == 4)   return 18;

        if(n >= 5){
            return  ((n - 5)*6 + 30) % 1000000007;
        }

        return 0;
    };

    for(int i = 1; i < 20; ++i){
        std::cout << i << ":  " << f2(i) << std::endl;
    }
}
