
#include<stack>
#include<climits>
#include<iostream>
class ReverseStackWithRecursive{

public:
    /**
     * @brief Get the maximum value within the range of depth starting from the top of the stack. 
     * @return the maxium of the stack
     */
    int getMax(std::stack<int>& St, int depth){
        if(depth == 0){
            return INT_MIN;
        }
        else{
            int _top = St.top();
            St.pop();

            int restMax = getMax(St, depth-1);
            int _max = _top > restMax ? _top : restMax;
            St.push(_top);

            return _max;
        }
    }

    /**
     * @brief get the times of `elem` in `St`
     */
    int times(std::stack<int>& St, int elem, int depth){
        if(depth == 0){
            return 0;
        }
        else{
            int _top = St.top();
            St.pop();
            int restTimes = times(St, elem, depth-1);
            St.push(_top);

            return _top == elem ? restTimes + 1 : restTimes;
        }
    }

    /**
     * @brief move all the elem in the stack to the bottom, and keep the order of other elems
     * @param `times`: The number of times `elem` appears in the stack
     */
    void down(std::stack<int>& St, int elem, int times, int depth){
        if(depth == 0){
            for(int i = 0; i < times; ++i){
                St.push(elem);
            }
        }
        else{
            int _top = St.top();
            St.pop();
            down(St, elem, times, depth-1);
            if(_top != elem){
                St.push(_top);
            }
        }
    }

    /**
     * @brief sort the stack
     * 
     */

    void sort(std::stack<int>& St){
        int depth = St.size();
        while(depth > 0){
            int _max = getMax(St, depth);
            int _times = times(St, _max, depth);
            down(St, _max, _times, depth);
             
            depth -= _times;
        }
    }
    
    void print(std::stack<int>& St){
        if(St.empty()){
            return;
        }
        else{
            int _top = St.top();
            St.pop();
            std::cout << _top << std::endl;

            print(St);
            St.push(_top);
        }
    }
};

int main(){
    std::stack<int> St;
    for(int i = 0; i < 10; ++i){
        St.push(i);
    }

    ReverseStackWithRecursive RSWR;
    RSWR.print(St);
    RSWR.sort(St);
    RSWR.print(St);

    return 0;

}