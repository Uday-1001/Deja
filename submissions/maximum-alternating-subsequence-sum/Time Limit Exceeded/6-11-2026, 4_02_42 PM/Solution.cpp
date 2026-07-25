// https://leetcode.com/problems/maximum-alternating-subsequence-sum

class Solution {
public:
    using ll = long long;

    ll solve(vector<int>&nums , int i , bool iseven)
    {
        //base case
        if(i >= nums.size()) return 0;

        //include case
        ll include = 0;
        ll sum = 0;

        if(iseven) 
            sum += nums[i] + solve(nums , i+1 , false);
        else 
            sum += -nums[i] + solve(nums , i+1 , true);
            
        include = max(include , sum);

        //exclude case
        ll exclude = 0 + solve(nums , i+1 , iseven);

        return max(include , exclude);
    }

    long long maxAlternatingSum(vector<int>& nums) {
        return solve(nums , 0 , true);
    }
};