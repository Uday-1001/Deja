// https://leetcode.com/problems/min-stack

class MinStack {
public:
    vector<pair<int , int>>v;
    //pair stores 2 things -> {value , min. element till now}
    MinStack() {
        
    }
    
    void push(int val) 
    {
        if(v.empty()) 
        {
            v.push_back({val , val});
            return;
        }
        int min = val;
        if(v.back().second < min)
        {
            min = v.back().second;
        }
        v.push_back({val , min});   
    }
    
    void pop() 
    {
        v.pop_back();
    }
    
    int top() 
    {
        return v.back().first;
    }
    
    int getMin() 
    {
        return v.back().second;
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