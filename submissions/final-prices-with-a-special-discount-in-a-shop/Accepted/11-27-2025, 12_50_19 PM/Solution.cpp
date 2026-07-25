// https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop

class Solution {
public:
    vector<int>nextsmaller(vector<int>&prices)
    {
        stack<int>st;
        st.push(-1);
        vector<int>nextsmaller(prices.size() , 0);

        for(int i = prices.size()-1 ; i>=0 ;  i--)
        {
            int element = prices[i];
            while(st.top() != -1 and prices[st.top()] > element)
            {
                st.pop();
            }
            nextsmaller[i] = st.top();
            st.push(i);
        }
    return nextsmaller;
    }

    vector<int> finalPrices(vector<int>& prices) {
        auto next_ans_indexes = nextsmaller(prices);

        for(int i=0 ; i<next_ans_indexes.size() ; i++)
        {
            next_ans_indexes[i] = (next_ans_indexes[i] == -1) ? 0 : prices[next_ans_indexes[i]];
        }

        vector<int>ans;
        for(int i =0; i<next_ans_indexes.size() ; i++)
        {
            ans.push_back(prices[i] - next_ans_indexes[i]);
        }
    return ans;
    }
};