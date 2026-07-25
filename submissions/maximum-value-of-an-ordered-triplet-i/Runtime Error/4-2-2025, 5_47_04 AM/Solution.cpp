// https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-i

class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        int max_val = 0;
        for(int i =0 ; i<n-2 ;i++)
        {
            for(int j=i+1 ; j<n-1 ;j++)
            {
                for(int k = j+1 ; k<n ; k++)
                {
                    int val = (nums[i]-nums[j]) * nums[k];
                    max_val = max(max_val , val);
                }
            }
        }
    return max_val;
    }
};