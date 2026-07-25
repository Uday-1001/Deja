// https://leetcode.com/problems/minimum-operations-to-convert-all-elements-to-zero

class Solution {
public:
    int minOperations(vector<int>& nums) {
        stack<int>st;
        unordered_set<int>set;
        int opr = 1;

        if(nums.size() > 1 and (nums[0] == 0 or nums[1] == 0)) return 1;
        if(nums.size() == 1 and nums[0] == 0) return 0;

        st.push(nums[0]);
        set.insert(nums[0]);
        for(int i=1 ; i<nums.size() ; i++)
        {
            if(st.top() <= nums[i] && !set.count(nums[i]))
            {
                st.push(nums[i]);
                set.insert(nums[i]);
                opr++;
            }
            if(st.top() > nums[i] && set.count(nums[i]))
            {
                int top = st.top();
                st.pop();
                set.erase(top);
            }
            if(st.top() > nums[i] && !set.count(nums[i]))
            {
                st.push(nums[i]);
                set.insert(nums[i]);
                opr++;
            }
        }
    return opr;
    }
};