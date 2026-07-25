// https://leetcode.com/problems/count-complete-subarrays-in-an-array

class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int>st;
        //getting the number of distinct elements
        for(auto num : nums)
        {
            st.insert(num);
        }
        int total_distinct = st.size();

        //calculating the complete subarrays
        int curr_distinct = 0;
        int left = 0 ;
        int right = 0;
        int completed = 0;

        unordered_map<int,int>mp;

        while(right < nums.size())
        {
            mp[nums[right]] ++;
            if(mp[nums[right]] == 1)
            {
                curr_distinct ++;
            }
            while(curr_distinct == total_distinct)
            {
                completed += nums.size() - right;
                mp[nums[left]] --;
                if(mp[nums[left]] == 0)
                {
                    curr_distinct --;
                }
                left ++;
            }
            right ++;
        }
        return completed;  
    }
};