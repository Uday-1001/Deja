// https://leetcode.com/problems/min-stack

class MinStack {
public:
    using pi = pair<int,int>;
    stack<pi>st;

    MinStack() {
        
    }
    
    void push(int value) {
        if(st.empty()) st.push({value,value});
        else
        {
            auto [val , minelem] = st.top();
            if(value < minelem) minelem = value;
            st.push({value , minelem});
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */