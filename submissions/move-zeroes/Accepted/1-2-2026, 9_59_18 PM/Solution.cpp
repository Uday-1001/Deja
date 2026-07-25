// https://leetcode.com/problems/move-zeroes

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        stack<int>st;
        for(int i = nums.size()-1 ; i>=0 ; i--) st.push(nums[i]);

        int count = st.size();
        int i = 0 , j = nums.size()-1;

        while(count > 0)
        {
            int top = st.top(); st.pop();
            if(top == 0)
            {
                nums[j] = 0;
                j--;
            }
            else 
            {
                nums[i] = top;
                i++;
            }
            count--;
        }
    }
};