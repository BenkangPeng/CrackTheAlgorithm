/*
 * @lc app=leetcode.cn id=3000 lang=cpp
 *
 * [3000] 对角线最长的矩形的面积
 */
#include <algorithm>
#include<vector>
using std::vector;
// @lc code=start
class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
       
        int len, width;
        int line, area;
        int max_line = 0, max_area = 0;
        for(auto dimension: dimensions){
            len = dimension[0];
            width = dimension[1];

            line = len * len + width * width;
            if(max_line < line){
                max_line = line;
                max_area = len * width;
            }
            else if(max_line == line){
                max_area = std::max(max_area, len * width);
            }

        }
        return max_area;
    }
};
// @lc code=end

