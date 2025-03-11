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
            f(i-1, from, other, to);
            std::cout << "move " << i << " from " << from << " to " << to << std::endl;
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
public:
    void hanota(std::vector<int>& A, std::vector<int>& B, std::vector<int>& C) {
        
    }
};


