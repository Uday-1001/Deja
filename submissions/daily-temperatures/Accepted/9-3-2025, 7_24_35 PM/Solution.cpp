// https://leetcode.com/problems/daily-temperatures

class Solution {
public:
    vector<int> nextsmaller(vector<int>& arr)
    {
        stack<int>st;
        st.push(-1);

        vector<int>nextans(arr.size() , 0);

        for(int i=arr.size()-1 ; i>=0 ; i--)
        {
            int element = arr[i];

            while(st.top() != -1 && arr[st.top()] <= element)
            {
                st.pop();
            }
            //yha pr hume smaller num he mila hoga tbhi loop exit hua hai
            nextans[i] = st.top();
            st.push(i);
        }
    return nextans;
    }
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int>ans(temperatures.size() , 0);

        auto next_tempidx = nextsmaller(temperatures);

        // for(int i=0 ; i<next_tempidx.size() ; i++)
        // {
        //     next_tempidx[i] = (next_tempidx == -1) ? 0 : next_tempidx;
        // }

        for(int i=0 ; i<temperatures.size() ; i++)
        {
            ans[i] = (next_tempidx[i] - i) > 0 ? (next_tempidx[i] - i) : 0;
        }
        return ans;
    }
};