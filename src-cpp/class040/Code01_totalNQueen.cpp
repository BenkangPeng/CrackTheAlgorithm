/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N 皇后 II
 */
#include<iostream>
#include<cstdlib>
#include<chrono>
// @lc code=start
class Solution {
private:
    /**
     * 记录皇后的位置
     * e.g path[i] = j表示第i行第j列有一个皇后
     */
    int path[32] = {0};
    
    /**
     * @brief 从第i行开始放置皇后，有多少种方法
     */
    int f2(int i, int n){
        
        int ans = 0;
        if(i == n){
            return 1;
        }
        else{
            for(int k = 0; k < n; ++k){//遍历列
                if(check(i, k, n)){
                    path[i] = k;//在(i,k)处放置皇后
                    ans += f2(i+1, n);//递归
                }
            }
        }

        return ans;
    }

    /**
     * 检查第i行第k列(i,k)能否放置皇后
     * @param n: N皇后问题规模
     */
    bool check(int i, int k, int n){
        for(int m = 0; m < i; ++m){//遍历[0,i)行
            //第二个判断式判定通过判定两点间的斜率(或者判定等腰直角三角形)，
            //从而实现对角线的判断
            if(path[m] == k || std::abs(m - i) == std::abs(path[m] - k)){
                return false;
            }
        }

        return true;
    }

    //通过位运算实现更高效的N皇后问题求解

    /**
     * @brief 返回当前限制下解法的总数
     * @param limits: 低n位置一的mask
     * @param col: 表示**当前行**可以放置皇后的位置；用bit位表示哪些列可以放皇后，0为可以放置
     * @param left: **之前的row**中皇后产生的向左的对角线对当前行的约束; 0表示可以放置
     * @param right: **之前的row**中皇后产生的向右的对角线对当前行的约束；0表示可以放置
     * @details 例如n=4, limits = 32'b1111
     * col = 32'b1000表示当前行第3列不能放置皇后；
     * 这个皇后对下一行的影响是对角线left = col >> 1(第二列不能放置皇后), right = col << 1
     * 
     */
    int f(int limits, int col, int left, int right){
        //注释中均采用n=4来举例
        if(col == limits){//每一行都只放一个皇后，col=limits时表示每行都放了一个皇后，导致列约束全满，说明已经遍历完所有行
            return 1;
        }
        
        int ban = col | left | right;//之前行的皇后产生的列约束、对角线约束的总和
        int candidate = limits & (~ban);//取反，&mask; 表示可以放置皇后的候选位置；1表示可以放置

        int place = 0;//当前行尝试放置皇后的位置，eg place = 32'b0010表示尝试在第1列放置一个皇后
        int ans = 0;
        while(candidate != 0){//还有候选位置
            place = candidate & (-candidate);//取候选位置的最后一个1
            //例如candidate = 32'b1010; 那么可以在第1,3列放置皇后，先尝试在第1列放置，place = 32'b0010
            candidate ^= place;//标记已经放置皇后的位置，candidate = 32'b1000

            //递归
            ans += f(limits, col | place, (left | place)>>1, (right | place)<<1);
        }
        

        return ans;
    }
public:
    int totalNQueens(int n){
        ///掩码，低n位置一
        int limits = (1 << n) - 1;
        return f(limits, 0, 0, 0);//col=left=right=0, 从第0行开始，没有任何限制

        ///用位运算来表示约束条件的一个关键点是：
        ///若第i行皇后放置在第1列，即32’b0010, 那么这个皇后对下一行的对角线约束为32'b0010 << 1 = 32'b0100
        ///第二列不能放皇后；32'b0010 >> 1, 第0列不能放置皇后
    }

    int totalNQueens2(int n) {
        return f2(0, n);
    }

    
};
// @lc code=end

int main(){
    Solution s;

    //对比以上两种方法的速度差距
    int n = 14;

    auto start1 = std::chrono::high_resolution_clock::now();
    std::cout << s.totalNQueens(n) << std::endl;
    auto stop1 = std::chrono::high_resolution_clock::now();
    auto duration1 = std::chrono::duration_cast<std::chrono::milliseconds>(stop1-start1);

    auto start2 = std::chrono::high_resolution_clock::now();
    std::cout << s.totalNQueens2(n) << std::endl;
    auto stop2 = std::chrono::high_resolution_clock::now();
    auto duration2 = std::chrono::duration_cast<std::chrono::milliseconds>(stop2-start2);

    std::cout << "Bit operation solution costs " << duration1.count() << "ms" << std::endl;

    std::cout << "Normal solution costs " << duration2.count() << "ms" << std::endl;

    return 0;
}