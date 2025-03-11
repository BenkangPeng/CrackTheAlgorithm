#include<iostream>

class binary_system{

    public:
        void print_binary(int x){
            for(int i = 31 ; i >= 0 ; --i){
                std::cout << ( (x >> i) & 1 ? '1' : '0' ) ;
            }
            std::cout << std::endl;
        }
};
int main()
{
    binary_system B;
    B.print_binary(6);
    B.print_binary(-10);
    //如何看11111111111111111111111111110110是-10：
    //符号位为-1 ， 其余31位取反加一得000……1010 ， -10
    //32位有符号数表示，[-2^31 : 2^31-1]

    int x = 0b0011;
    B.print_binary(x);


    int y = 0x4f;
    B.print_binary(y);
    B.print_binary(~y);
    B.print_binary(~y >> 1);
}