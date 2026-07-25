// https://leetcode.com/problems/number-of-visible-people-in-a-queue

class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        stack<int>st;
        vector<int>ans(n , 0);
        st.push(n-1);

        for(int i = n-2 ; i>=0 ; i--)
        {
            int count = 0;
            while(!st.empty() and heights[i] > heights[st.top()])
            {
                st.pop();
                count++;
            }
            if(!st.empty()) count++;
            ans[i] = count;
            st.push(i);
        }
    return ans;
    }
};