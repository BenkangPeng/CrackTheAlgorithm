
#include<stack>
class ReverseStackWithRecursive{


public:


    /**
     * @brief Remove the element at the bottom of stack and return it
     * Complexity: O(N)
     * @param St: the stack operated
     * @return the element of stack's bottom
     */
    int bottom_out(std::stack<int>& St){
        
        int ans = St.top();
        St.pop();
        if(St.empty()){
            return ans;
        }
        else{
            int last = bottom_out(St);
            St.push(ans);
            return last;
        }

    }

    /**
     * reverse the order of the stack
     * complexity: O(N^2)
     */
    void reverse(std::stack<int>& St){
        if(St.empty()){
            return;
        }
        else{
            int num = bottom_out(St);
            reverse(St);
            St.push(num);
        }
    }
};


