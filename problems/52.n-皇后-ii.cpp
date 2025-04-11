/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N 皇后 II
 */

// @lc code=start
class Solution {
private:
    int f(int limits, int col, int left, int right){
        if(col == limits){
            return 1;
        }
        
        int ans = 0;
        int ban = col | left | right;
        int candidate = limits & (~ban);
        
        while(candidate != 0){
            int place = candidate & (-candidate);
            candidate ^= place;
            ans += f(limits, col | place, (left | place) >> 1, (right | place)<<1);
        }

        return ans;
    }
public:
    int totalNQueens(int n) {
        int limits = (1 << n) - 1;
        return f(limits, 0, 0, 0);
    }
};
// @lc code=end

