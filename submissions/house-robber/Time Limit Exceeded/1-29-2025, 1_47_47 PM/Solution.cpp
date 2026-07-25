// https://leetcode.com/problems/house-robber

class Solution {
public:
    int solve (vector<int>& nums ,int n, int i)
    {
        if(i >= n){
        return 0 ;
        }
        int includeAns = nums[i] + solve(nums,n,i+2);
        int excludeAns = 0 + solve(nums,n,i+1);

        int final = max(includeAns,excludeAns);
        return final;
    }
    int rob(vector<int>& nums) {
        int index = 0;
        int ans = solve(nums,nums.size(),index);
        return ans;
    }
};