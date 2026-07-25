// https://leetcode.com/problems/maximum-sum-of-three-numbers-divisible-by-three

class Solution {
public:
    int maximumSum(vector<int>& nums) {
        vector<int> rem0;
        vector<int> rem1;
        vector<int> rem2;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] % 3 == 0) rem0.push_back(nums[i]);
            else if(nums[i] % 3 == 1) rem1.push_back(nums[i]);
            else rem2.push_back(nums[i]);
        }
        sort(rem0.rbegin(),rem0.rend());
        sort(rem1.rbegin(),rem1.rend());
        sort(rem2.rbegin(),rem2.rend());

        int ans = 0;
        if(rem0.size() >= 3)
        {
            ans = max(ans, (rem0[0] + rem0[1] + rem0[2]));
        }
        if(rem1.size() >= 3)
        {
            ans = max(ans, (rem1[0] + rem1[1] + rem1[2]));
        }
        if(rem2.size() >= 3)
        {
            ans = max(ans, (rem2[0] + rem2[1] + rem2[2]));
        }
        if(!rem0.empty() && !rem1.empty() && !rem2.empty())
        {
            ans = max(ans, (rem0[0] + rem1[0] + rem2[0]));
        }

        return ans;
    }
};