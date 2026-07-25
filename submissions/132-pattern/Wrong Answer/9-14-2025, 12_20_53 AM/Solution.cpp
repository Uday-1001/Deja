// https://leetcode.com/problems/132-pattern

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        stack<int>st;

        int middle_candidate = INT_MIN;

        for(int i=nums.size()-1 ; i>=0 ; i--)
        {
            if(st.empty())
            {
                st.push(nums[i]);
            }
            while(!st.empty() && nums[i] > st.top()) 
            {
                middle_candidate = st.top();
                st.pop();
            } 
            // st.push(nums[i]);

            if(nums[i] < middle_candidate) return true;
        }
    return false;
    }
};