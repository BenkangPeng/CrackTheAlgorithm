
#include<iostream>
class BitOperationAddMinusMultiplyDivide{

private:
    int neg(int x){//取相反数
        return add(~x , 1);// 取反加一，变成相反数
    }


public:
    int add(int a , int b){
        int ans = a ^ b;//无进位相加
        int carry = (a & b) << 1;//相加时的进位信息
        while(carry != 0){
            int _carry = (ans & carry) << 1;
            ans ^= carry;
            carry = _carry;
            
        }
        return ans;
    }
    int add2(int a , int b){
        int ans = a ^ b;//无进位相加
        int carry = (a & b) << 1;//相加时的进位信息
        while(carry != 0){
            int _carry = (ans & carry) << 1;
            ans ^= carry;
            carry = _carry;
        }
        return ans;
    }

    int minus(int a , int b){
        return add(a , neg(b));
    }

    int multiply(int a , int b){
        int ans = 0;
        while(b != 0){
            if((b & 1) != 0){
                ans = add(ans , a);
            }
            b >>= 1;
            b &= ~(1 << 31); // cpp没有java中的>>>无符号右移，因此需要手动处理符号位
            a <<= 1;
        }

        return ans;
    }

    int div(int a , int b){


        //取绝对值
        //注意，此处要求传入的a,b不能是INT_MIN，因为-INT_MIN会溢出（INT_MIN = -INT_MAX - 1）
        int x = a < 0 ? neg(a) : a;
        int y = b < 0 ? neg(b) : b;
        
        int ans = 0;
        for(int i = 30 ; i >= 0 ; i = minus(i , 1)){//i从30开始，寻找x >= (y << i) , 若if成立，x/y可以得出一个(1 << i)
        //x = x - (y << i),再继续判断
            if((x >> i) >= y){//这里不写成if(x >= y << i),因为y << i有溢出风险
                ans |= (1 << i);
                x = minus(x , y << i);//此处y << i无溢出风险，因为if(x >> i >= y)保证了x >= y << i
                //x都没有溢出，y << i肯定也不会溢出
            }
        }
        return a < 0 ^ b < 0 ? neg(ans) : ans;


    }

    int divide(int a , int b){
        //需要对a,b是整数最小值做出判断,因为div()传入参数不能是INT_MIN
        if(a == INT_MIN && b == INT_MIN)    return 1;

        if(a != INT_MIN && b != INT_MIN)    return div(a , b);

        if(b == INT_MIN)    return 0;

        if(a == INT_MIN){
            if(b == neg(1)) return INT_MAX;
            else{
                a = add(a , b > 0 ? b : neg(b));
                int ans = div(a ,b);
                int offset = b > 0 ? -1 : 1;
                return add(ans , offset);
            }
        }


    }

    
};

int main()
{
    BitOperationAddMinusMultiplyDivide b;
    std::cout << b.add(-11,13) << std::endl;
    std::cout << b.multiply(5 , -3) << std::endl;

    return 0;
}