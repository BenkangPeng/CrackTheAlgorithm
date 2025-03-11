// 位图就是用整数的位信息存放数据
// 例如，给定一个整数：int32_t x = 0;
// 这一个数有32 bits(0 ~ 31)，每一个bit可以存放一个数，这一个数构成的位图可以存放0 ~ 31的数字
// 如果存入5 ， 那么将x的第5个比特位 置为1 ， x = 16
// 再存入4 ， x的第4个比特位 置为1 ， x = 8

// 扩展位图的范围，可以使用更多的数构建位图

#include<iostream>
#include<string>
class bitset{
    public:

        int* set;

        bitset(int n){
            set = new int[(n + 31) / 32];//n表示该位图需要存储0 ~ n-1的数
            //那么需要“n/32向上取整”个整数来 ， n/32向上取整常写成：(n + 31)/32
        }
        
        void add(int num){//向位图中加入num
            set[num/32] |= (1 << (num % 32));
            // num / 32找到num要存在哪个数中
            // num % 32得出存在哪一位上
        }
        
        void remove(int num){
            set[num/32] &= ~(1 << (num % 32));
        }

        void reverse(int num){
            set[num/32] ^= (1 << (num % 32));
        }

        bool contain(int num){
            return (set[num/32] >> (num % 32)) & 1 == 1;
        }


        
};

// https://leetcode.cn/problems/design-bitset/description/

#include<cstring>
class Bitset {
public:
    int n, size;
    int* set;
    bool reverse = false;//表示状态是否经过了翻转，reverse = false代表：位为1时，表示该数存在 ； reverse = true：0表示该数存在
    int ones = 0;//1的位的数量
    int zeros ;

    Bitset(int size): size(size) , n((size + 31)/32) , zeros(size) {
        set = new int[n];
        memset(set , 0 , n * sizeof(int));//new 分配内存空间不会初始化
    }
    
    void fix(int idx) {
        int _idx = idx / 32;
        int bit = idx % 32;

        if(!reverse){//0表示不存在
            if((set[_idx] & (1 << bit)) == 0){//注意运算符优先级，不能写成if(set[_idx] & (1 << bit) == 0)
                ones++;
                zeros--;
                set[_idx] |= (1 << bit);
            }
        }
        else{//1表示不存在
            if((set[_idx] & (1 << bit)) != 0){
                ones++;
                zeros--;
                set[_idx] &= ~(1 << bit);
            }
        }
    }
    
    void unfix(int idx) {
        int _idx = idx / 32;
        int bit = idx % 32;

        if(!reverse){//1表示存在
            if((set[_idx] & (1 << bit)) != 0){
                ones--;
                zeros++;
                set[_idx] &= ~(1 << bit);
            }
        }
        else{//0表示存在
            if((set[_idx] & (1 << bit)) == 0){
                ones--;
                zeros++;
                set[_idx] |= (1 << bit);
            }
        }
    }
    
    void flip() {
        reverse = !reverse;//reverse的妙处在这
        int tmp = zeros;
        zeros = ones;
        ones = tmp;
    }
    
    bool all() {
        return ones == size;
    }
    
    bool one() {
        return ones > 0;
    }
    
    int count() {
        return ones;
    }
    
    std::string toString() {
        std::string ans;
        for(int i = 0 , k = 0; i < n ; i++){//遍历每一个数
            for(int j = 0 ; j < 32 && k < size ; j++ , k++){//k来记录位数，注意k是总位数，要小于size(set[n-1]可能没填满)
                int state = (set[i] >> j) & 1;
                state = reverse ? (state ^ 1) : state;
                ans.push_back(state + '0');
            }
        }

        return ans;
    }
};

int main()
{
    Bitset b(5);
    b.fix(3);
    b.fix(1);
    b.flip();
    std::cout << b.all() << std::endl;
    b.unfix(0);
    b.flip();
    std::cout << b.one() << std::endl;
    b.unfix(0);
    std::cout << b.count() << std::endl;
    std::cout << b.toString() << std::endl;



}

/**
 * Your Bitset object will be instantiated and called as such:
 * Bitset* obj = new Bitset(size);
 * obj->fix(idx);
 * obj->unfix(idx);
 * obj->flip();
 * bool param_4 = obj->all();
 * bool param_5 = obj->one();
 * int param_6 = obj->count();
 * string param_7 = obj->toString();
 */