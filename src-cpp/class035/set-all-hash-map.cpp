// https://www.nowcoder.com/practice/7c4559f138e74ceb9ba57d76fd169967?tpId=101&&tqId=33130&rp=1&ru=/ta/programmer-code-interview-guide&qru=/ta/programmer-code-interview-guide/question-ranking

// 为哈希表添加一个set_all的功能
// 将哈希表中所有的键值均设为set_all_val , 同时保证时间复杂度为O(1)

// 时间复杂度要求O(1)，那么肯定不能去修改每一个键值对(O(N))
// 引入一个时间戳
// 给每个键值对赋值的同时，记录当前时间
// 每次set_all时，记录每次set_all操作时的时间与set_all_value
// 取某个键值时，做一次判断，如果set_all操作的时间晚于该键值对赋值的时间，那么取出set_all_value，反之取出键值

#include <cstdio>
#include <iostream>
#include<unordered_map>
#include<array>
using namespace std;

int main() {
    unordered_map<int , array<int , 2>> map;

    int N;
    cin >> N;
    int opt , x , y;
    int set_all_val = -1;
    int set_all_time = 0;
    int cnt = 0;

    while(N--){
        scanf("%d" , &opt);
        if(opt == 1){
            scanf("%d %d" , &x , &y);
            map[x][0] = y;
            map[x][1] = cnt++;
        }
        else if(opt == 2){
            scanf("%d" , &x);
            if(map.find(x) == map.end()){
                printf("%d\n" , -1);
            }
            else{
                if(map[x][1] < set_all_time){
                    printf("%d\n" , set_all_val);
                }
                else{
                    printf("%d\n" , map[x][0]);
                }
            }
        }
        else{
            scanf("%d" , &x);
            set_all_time = cnt++;
            set_all_val = x;
        }
    }
}