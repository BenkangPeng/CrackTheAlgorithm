// https://www.nowcoder.com/practice/1ae8d0b6bb4e4bcdbf64ec491f63fc37

#include<iostream>
#include<vector>
#include<array>
#include<queue>
#include<algorithm>

struct comparator
{
    bool operator()(int a , int b){
        return a > b;
    }
};


bool compare_lines(const std::array<int , 2>& a , const std::array<int , 2>& b){
    return a[0] < b[0];
}



int main()
{
    int n;
    const int MAXN = 10001;
    std::array<std::array<int , 2> , MAXN> lines;
    std::cin >> n;

    for(int i = 0 ; i < n ; i++){
        std::cin >> lines[i][0] >> lines[i][1];
    }

    std::sort(lines.begin() , lines.begin() + n , compare_lines);

    std::priority_queue<int , std::vector<int> , comparator> min_heap;
    int ans = 0;

    for(int i = 0 ; i < n ; i++){
        while(min_heap.size() > 0 && min_heap.top() <= lines[i][0]){
            min_heap.pop();
        }

        min_heap.push(lines[i][1]);
        ans = ans >= min_heap.size() ? ans : min_heap.size();
    }

    std::cout << ans;

    return 0;
}

// 区间合并 https://leetcode.cn/problems/merge-intervals/description/

class Solution {
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
        
        std::sort(intervals.begin() , intervals.end());
        int n = intervals.size();
        int l = intervals[0][0] , r = intervals[0][1];
        std::vector<std::vector<int>> ans;
        for(int i = 0 ; i < n ; i++){
            int start = intervals[i][0] , end = intervals[i][1];
            if(start <= r && end >= r)    r = end; 
            else if(start > r){
                ans.push_back({l , r});
                l = start;
                r = end;
            }
        }

        ans.push_back({l , r});
        return ans;
    }
};