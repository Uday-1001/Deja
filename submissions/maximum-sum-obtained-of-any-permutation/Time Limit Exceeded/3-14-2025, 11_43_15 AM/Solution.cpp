// https://leetcode.com/problems/maximum-sum-obtained-of-any-permutation

class Solution {
public:
    int next_perm(vector<int>& nums, vector<vector<int>>& requests , int &max_sum)
    {
        vector<int>presum(nums.size());
            int sum = 0 ;
            for(int i = 0 ; i<nums.size(); i++)
            {
                sum += nums[i];
                presum[i] = sum;
            }
            int pre_sum =0;
            for(int i=0 ; i<requests.size() ;i++)
            {
                int start = requests[i][0];
                int end =  requests[i][1];
                if(start-1 >= 0) 
                pre_sum += presum[end] - presum[start-1];
                else
                pre_sum += presum[end];

                max_sum = max(max_sum , pre_sum);
            }
        return max_sum;
    }
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int max_sum = INT_MIN;
        sort(nums.begin(), nums.end());
        int first_sum = next_perm(nums, requests , max_sum);
        max_sum = max(max_sum , first_sum);
        
        while(next_permutation(nums.begin(), nums.end()))
        {
            int next_sum = next_perm(nums , requests , max_sum);
            max_sum = max(max_sum , next_sum);

        }
    return max_sum;
    }
};