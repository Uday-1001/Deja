// https://leetcode.com/problems/maximum-width-ramp

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        stack<int>st;

        for(int i = 0 ; i<nums.size() ; i++)
        {
            if(st.empty() or nums[st.top()] > nums[i]) st.push(i);
        }

        int maxwidth = 0;
        for(int i = nums.size()-1 ; i>=0 ; i--)
        {
            while(!st.empty() and nums[st.top()] <= nums[i])
            {
                maxwidth = max(maxwidth , i - st.top());
                st.pop();
            }
        }
        return maxwidth;
    }
};