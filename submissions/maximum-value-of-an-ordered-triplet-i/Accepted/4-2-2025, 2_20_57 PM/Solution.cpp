// https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-i

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long max_val = INT_MIN;
        for(int j = 0 ; j<nums.size() ; j++)
        {
            int i =0;
            int k = nums.size()-1;
            long long max_i = 0;
            long long max_k = 0;

            for(int i = 0 ; i<j ; i++)
            {
                max_i = max(max_i , (long long)nums[i]);
            }
            for(int k = j+1 ; k<nums.size() ; k++)
            {
                max_k = max(max_k , (long long)nums[k]);
            }

            max_val = max(max_val , (long long)(max_i - nums[j])* max_k);
        }
    return max_val;
    }
};