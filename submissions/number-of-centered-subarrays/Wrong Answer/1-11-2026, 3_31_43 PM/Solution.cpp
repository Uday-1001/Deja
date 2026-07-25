// https://leetcode.com/problems/number-of-centered-subarrays

class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        int n = nums.size();    
        int count = 0;
        set<int>st;

        for(int i =0 ; i<n ; i++)
        {
            int sum = 0;
            for(int j =i ; j<n ; j++)
            {
                sum += nums[j];
                st.insert(nums[j]);
                if(st.count(sum)) count++;
            }
        }
    return count;
    }
};