/*
Question# + Difficulty + Topic + Company + Similar_Question
[155] [Min Stack] [Easy] [Stack Design ] 
[Google Uber Zenefits Amazon Snapchat Bloomberg ] 
[239].cpp
*/

/* Two Stack*/
class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> sta;
    stack<int> mini;
    MinStack() {
    }
    
    void push(int x) {
        sta.push(x);
        if(mini.empty()||x<=getMin()) mini.push(x);
    }
    
    void pop() {
        if(sta.top()==getMin()) mini.pop();
        sta.pop();
    }
    
    int top() {
        return sta.top();
    }
    
    int getMin() {
        return mini.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
 
 
