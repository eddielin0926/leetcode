class MinStack {
    stack<int> stck;
    stack<int> minstck;
public:
    MinStack() {

    }
    
    void push(int val) {
        if (stck.empty())
            minstck.push(val);
        else
            minstck.push(min(val, minstck.top()));
        stck.push(val);
    }
    
    void pop() {
        if (stck.empty())
            return;
        stck.pop();
        minstck.pop();
    }
    
    int top() {
        if (stck.empty())
            return INT_MAX;
        return stck.top();
    }
    
    int getMin() { 
        if (stck.empty())
            return INT_MAX;
        return minstck.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */