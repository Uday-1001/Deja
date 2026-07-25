// https://leetcode.com/problems/transformed-array

class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n , 0);

        for(int i = 0 ; i<n ; i++)
        {
            if(nums[i] == 0) ans[i] = nums[i];
            int k = nums[i] % n;
            if(k < 0) k += n;
            ans[i] = nums[(i + k) % n];
        }
        return ans;
    }
};