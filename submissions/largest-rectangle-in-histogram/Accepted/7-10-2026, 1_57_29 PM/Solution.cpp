// https://leetcode.com/problems/largest-rectangle-in-histogram

class Solution {
public:
    int MonotonicStack(vector<int>&nums)
    {
        int n = nums.size();

        vector<int>prevsmaller(n , -1);
        vector<int>nextsmaller(n , -1);

        stack<int>st;

        st.push(-1);
        for(int i = 0 ; i<n ; i++)
        {
            while(st.top() != -1 and nums[st.top()] >= nums[i]) st.pop();
            prevsmaller[i] = st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();

        st.push(-1);
        for(int i = n-1 ; i>=0 ; i--)
        {
            while(st.top() != -1 and nums[st.top()] >= nums[i]) st.pop();
            nextsmaller[i] = st.top();
            st.push(i);
        }

        for(auto &it : nextsmaller) if(it == -1) it = nextsmaller.size();
        
        int maxwidth = INT_MIN;
        for(int i = 0 ; i<n ; i++)
        {
            int width = nextsmaller[i] - prevsmaller[i] - 1;
            maxwidth = max(maxwidth , width * nums[i]);
        }

        return maxwidth;
    }

    int largestRectangleArea(vector<int>& heights) {
        return MonotonicStack(heights);
    }
};