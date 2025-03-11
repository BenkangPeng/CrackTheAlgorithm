#include<iostream>
class get_bigger{
private:
    int get_sign(int x){
        return (x >> 31) & 1;
    }
public:

    int get_bigger1(int a , int b){
        int c = a - b;
        int c_sign = get_sign(c);
        return c_sign * b + (!c_sign) * a;
    }

    //get_bigger1中c有溢出风险

    int get_bigger2(int a , int b){
        
    }
};


int main()
{
    get_bigger s;
    std::cout << s.get_bigger1(-20 , 0) << std::endl;
}