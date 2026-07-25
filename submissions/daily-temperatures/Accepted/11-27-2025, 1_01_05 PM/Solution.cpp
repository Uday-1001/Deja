// https://leetcode.com/problems/daily-temperatures

class Solution {
public:
    vector<int>nextgreater(vector<int>& temperatures)
    {
        stack<int>st;
        st.push(-1);
        vector<int>nextgreater(temperatures.size() , 0);

        for(int i = temperatures.size()-1 ; i>=0 ;  i--)
        {
            int element = temperatures[i];
            while(st.top() != -1 and temperatures[st.top()] <= element)
            {
                st.pop();
            }
            nextgreater[i] = st.top();
            st.push(i);
        }
    return nextgreater;  
    }

    vector<int> dailyTemperatures(vector<int>& temperatures) {
        auto next_ans_index = nextgreater(temperatures);
        vector<int>ans;
        for(int i=0 ; i<temperatures.size() ; i++)
        {
            if(next_ans_index[i] != -1) ans.push_back(next_ans_index[i] - i);
            else 
            ans.push_back(0);
        }
        return ans;
    }
};