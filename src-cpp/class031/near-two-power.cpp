// 已知n是非负数
// 返回大于等于n的最小的2某次方
// 如果int范围内不存在这样的数，返回整数最小值


// 2的幂，在2进制的视角下，总是以0001 ， 0010 ， 0100 ， 1000 ，10000等形式出现
// 因此对于非2的幂，举例来说，10 : 001010 , 最近的2的幂是010000，16
// 抽象而言，对于一个数n(非2的幂)，设二进制下，从高位起第一个1所在位索引为x，则最近的2的幂：x+1位为1，其他位为0
// 以下代码实现思路是先将n减1,再将低位全置成1，再加一
int near_2_power(int n){
    if(n <= 0)  return 1;

    n--;
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;

    return n + 1;
}