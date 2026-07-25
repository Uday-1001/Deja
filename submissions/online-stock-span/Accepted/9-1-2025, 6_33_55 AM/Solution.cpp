// https://leetcode.com/problems/online-stock-span

class StockSpanner {
public:
    //stores the {price , span} pair in it 
    stack<pair<int,int>>st;

    StockSpanner() {
        
    }
    
    int next(int price) {
        int span = 1;

        while(!st.empty() && (st.top().first <= price))
        {
            //this means current price is greater than the price present at the top of stack
            span += st.top().second;
            st.pop();
        }
        //push the element with the pair of price and span
        st.push({price , span});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */