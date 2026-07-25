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
            //adding the element in the map for checks 
            mp[nums[right]] ++;

            //check until the distinct elements are still present in the subarray
            while(mp.size() == total_distinct)
            {
                completed += nums.size() - right;
                //shrink the window
                mp[nums[left]] --;
                if(mp[nums[left]] == 0)
                {
                    mp.erase(nums[left]);
                }
                left ++;
            }
            right ++;
        }
        return completed;  
    }
};