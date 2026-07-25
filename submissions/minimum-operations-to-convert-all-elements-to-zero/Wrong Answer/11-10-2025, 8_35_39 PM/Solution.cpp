// https://leetcode.com/problems/minimum-operations-to-convert-all-elements-to-zero

class Solution {
public:
    int minOperations(vector<int>& nums) {
        stack<int>st;
        int opr = 0;

        for(int i=0 ; i<nums.size() ; i++)
        {
            if(nums[i] == 0) continue;
            
            while(!st.empty() and st.top() > nums[i])
            {
                st.pop();
            }
            if(st.empty() or (st.top() < nums[i]))
            {
                st.push(nums[i]);
                opr++;
            }
        }
    return opr;
    }
};