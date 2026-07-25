// https://leetcode.com/problems/product-of-array-except-self

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int>prefix(n,1);
        vector<int>suffix(n,1);
        vector<int>ans(n);

        for(int i = 1; i < n; i++)
            prefix[i] = prefix[i-1] * nums[i-1];

        for(int i = n-2; i >= 0; i--)
            suffix[i] = suffix[i+1] * nums[i+1];

        // for(auto it : prefix) cout<<it<<" ";
        // cout<<endl;
        // for(auto it : suffix) cout<<it<<" ";

        for(int i = 0; i < n; i++)
            ans[i] = prefix[i] * suffix[i];

        return ans;
    }
};