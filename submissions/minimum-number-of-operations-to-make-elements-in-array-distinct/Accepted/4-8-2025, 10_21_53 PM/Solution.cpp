// https://leetcode.com/problems/minimum-number-of-operations-to-make-elements-in-array-distinct

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int>st;
        int dup_index = -1;

        for(int i=n-1 ; i>=0 ; i--)
        {
            if(st.count(nums[i]))
            {
                dup_index = i;
                break;
            }
            st.insert(nums[i]);
        }
        
        if(dup_index == -1) return 0;

        int to_remove = dup_index + 1;

        return (to_remove + 2)/3;
    }
};