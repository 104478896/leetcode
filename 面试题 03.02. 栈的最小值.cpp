/*请设计一个栈，除了常规栈支持的pop与push函数以外，还支持min函数，该函数返回栈元素中的最小值。执行push、pop和min操作的时间复杂度必须为O(1)。*/
class MinStack {
private:
    stack<int>stk;
    stack<int>min_stk;
public:
    /** initialize your data structure here. */
    MinStack() {
        min_stk.push(INT_MAX);
    }
    
    void push(int x) {
        stk.push(x);
        min_stk.push(min(min_stk.top(),x));
    }
    
    void pop() {
        stk.pop();
        min_stk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return min_stk.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */