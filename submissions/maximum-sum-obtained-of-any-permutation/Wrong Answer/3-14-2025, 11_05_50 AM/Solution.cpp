// https://leetcode.com/problems/maximum-sum-obtained-of-any-permutation

class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int max_sum = INT_MIN;
        sort(nums.begin(), nums.end());
        while(next_permutation(nums.begin(), nums.end()))
        {
            vector<int>presum(nums.size());
            int sum = 0 ;
            for(int i = 0 ; i<nums.size(); i++)
            {
                sum += nums[i];
                presum[i] = sum;
            }
            int next_sum =0;
            for(int i=0 ; i<requests.size() ;i++)
            {
                int start = requests[i][0];
                int end =  requests[i][1];
                if(start-1 >= 0) 
                next_sum += presum[end] - presum[start-1];
                else
                next_sum += presum[end];

                max_sum = max(max_sum , next_sum);
            }
        }
    return max_sum;
    }
};