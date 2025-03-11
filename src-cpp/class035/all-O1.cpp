// 432. https://leetcode.cn/problems/all-oone-data-structure/description/
// 题解见note.md

#include<string>
#include<unordered_map>
#include<unordered_set>
#include<climits>
using namespace std;

class bucket{
public:
    int cnt;//当前桶中字符串的频次
    unordered_set<string> set;
    bucket *next , *last;
    bucket(const string& str , int cnt): set({str}) , cnt(cnt) , next(nullptr) , last(nullptr){}

};


class AllOne {
private:
    unordered_map<string , bucket*> str_addr;//记录字符串对应的桶地址
    bucket* head;
    bucket* tail;

   void insert(bucket* cur , bucket* pos){//pos插到cur后面
        bucket* cur_next = cur->next;

        cur->next = pos;
        pos->last = cur;
        pos->next = cur_next;
        cur_next->last = pos;
   }

   void remove(bucket* cur){
        bucket* _last = cur->last;
        bucket* _next = cur->next;
        _last->next = _next;
        _next->last = _last;
        delete cur;
   }

public:
    AllOne() {
        head = new bucket("" , 0);
        tail = new bucket("" , 0);
        head->next = tail;
        tail->last = head;
    }
    
    void inc(string key) {
        if(str_addr.find(key) == str_addr.end()){//没找到该字符串,新字符串
            if(head->next->cnt != 1){//没有词频为1的桶
                bucket* tmp = new bucket(key , 1);//新建词频为1的桶
                insert(head , tmp);//insert自定义函数，将词频为1的桶插入head结点后
                str_addr[key] = tmp;//记录新字符串存储位置(桶的地址)
            }
            else{//有词频为1的桶，直接加入即可
                head->next->set.insert(key);
                str_addr[key] = head->next;
            }
             
        }
        else{//有这个字符串，旧字符串
            bucket* key_addr = str_addr[key];//找出该字符串存在哪个桶里
            if(key_addr->cnt + 1 != key_addr->next->cnt){//没有cnt + 1的桶，就新建一个
                bucket* tmp = new bucket(key , key_addr->cnt + 1);
                insert(key_addr , tmp);
            }
            
            key_addr->set.erase(key);
            key_addr->next->set.insert(key);
            str_addr[key] = key_addr->next;
            if(key_addr->set.empty()){//如果桶已经空了，则删除桶
                remove(key_addr);
            }
        }


        
    }
    
    void dec(string key) {
        bucket* key_addr = str_addr[key];
        if(key_addr->cnt == 1){//若该字符串词频为1，则直接将其从词频为1的桶中移除即可
            str_addr.erase(key);
        }
        else{// 该字符串词频大于1，则将该字符串移到`词频-1`的桶中
            if(key_addr->cnt - 1 == key_addr->last->cnt){
                key_addr->last->set.insert(key);
                str_addr[key] = key_addr->last;
            }
            else{
                bucket* tmp = new bucket(key , key_addr->cnt - 1);//新建词频为cnt-1的桶
                insert(key_addr->last , tmp);
                str_addr[key] = tmp;
            }
        }


        key_addr->set.erase(key);//从原桶中移除该字符串
        if(key_addr->set.empty()){//若移除后，桶空了，则删除桶
            remove(key_addr);
        }
    }
    
    string getMaxKey() {
        return *(tail->last->set.begin());
    }
    
    string getMinKey() {
        return *(head->next->set.begin());
    }
};


int main()
{
    // ["AllOne","inc","inc","getMaxKey","getMinKey","inc","getMaxKey","getMinKey"]
    // [[],["hello"],["hello"],[],[],["leet"],[],[]]

    AllOne s;
    s.inc("hello");
    s.inc("hello");
    s.getMaxKey();
    s.getMinKey();
    s.inc("leet");
    s.getMaxKey();
    s.getMinKey();
}

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */