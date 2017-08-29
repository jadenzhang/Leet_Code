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
 
 /* Only One Stack */
 public class MinStack {
    long min;
    Stack<Long> stack;

    public MinStack(){
        stack=new Stack<>();
    }
    
    public void push(int x) {
        if (stack.isEmpty()){
            stack.push(0L);
            min=x;
        }else{
            stack.push(x-min);//Could be negative if min value needs to change
            if (x<min) min=x;
        }
    }

    public void pop() {
        if (stack.isEmpty()) return;
        
        long pop=stack.pop();
        
        if (pop<0)  min=min-pop;//If negative, increase the min value
        
    }

    public int top() {
        long top=stack.peek();
        if (top>0){
            return (int)(top+min);
        }else{
           return (int)(min);
        }
    }

    public int getMin() {
        return (int)min;
    }
}
