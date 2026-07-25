// https://leetcode.com/problems/greatest-sum-divisible-by-three

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        sort(begin(nums) , end(nums));
        int sum = accumulate(begin(nums) , end(nums) , 0);
        int ans = INT_MIN;
        for(int i = 0 ; i<nums.size() ; i++)
        {
            sum -= nums[i];
            if(sum % 3 == 0)
                ans = max(ans , sum);
            else 
                sum += nums[i];
        }
    return ans;
    }
};