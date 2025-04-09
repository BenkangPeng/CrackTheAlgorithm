#include<string>
#include<iostream>
#include<vector>
class TowerOfHanoi{

private:
    

public:
    void hanoi(int n){
        f(n, "left plate", "right plate", "middle palte");
    }

    void f(int i, const std::string& from, const std::string& to, const std::string& other){
        if(i == 1){
            std::cout << "move " << i << " from " << from << " to " << to << std::endl;  
        }
        else{
            f(i-1, from, other, to);//将1,2...i-1的盘子搬到other

            //将盘子i搬到to
            std::cout << "move " << i << " from " << from << " to " << to << std::endl;
            
            //将盘子1，2...i-1搬到to
            f(i-1, other, to, from); 
        }
    }
};

int main()
{
    TowerOfHanoi Hanoi;
    Hanoi.hanoi(3);

    return 0;
}

// test: https://leetcode.cn/problems/hanota-lcci/description/

class Solution {
private:
    void move(int i, std::vector<int>& from, std::vector<int>& to, std::vector<int>& other){
        if(i == 1){
            int tmp = from.back();
            from.pop_back();
            to.push_back(tmp);
        }
        else{
            move(i-1, from, other, to);
            int tmp = from.back();
            from.pop_back();
            to.push_back(tmp);
            move(i-1, other, to, from);

        }
    }
public:
    void hanota(std::vector<int>& A, std::vector<int>& B, std::vector<int>& C) {
        int num = A.size();
        move(num, A, C, B);
    }
};


