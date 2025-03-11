// https://leetcode.cn/problems/maximum-frequency-stack/description/
// 这道题的解析画了一张图，见notes
#include<unordered_map>
#include<vector>
class FreqStack {
private:
    std::unordered_map<int , int> val_cnt;//记录每个数字出现的次数，简称词频表
    std::unordered_map<int , std::vector<int>> times_cnt;//一个根据词频构建的栈
    int top_times = 0;//所有数字中最高出现次数
public:
    FreqStack() {

    }
    
    void push(int val) {
        
        int val_times = ++val_cnt[val];//记录词频
        top_times = val_times < top_times ? top_times : val_times;//更新最大次数
        times_cnt[val_times].push_back(val);


    }
    
    int pop() {

        int ans = times_cnt[top_times].back();
        val_cnt[ans]--;
        if(times_cnt[top_times].size() == 1){
            times_cnt.erase(top_times);
            top_times--;
        }
        else{
            times_cnt[top_times].pop_back();
        }


        return ans;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */