// https://leetcode.com/problems/maximum-product-subarray

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int>pref(n , 0);
        vector<int>suff(n , 0);
        pref[0] = nums[0];
        suff[n-1] = nums[n-1];

        for(int i = 1 ; i < n ; i++)
        {
            pref[i] = pref[i-1] * nums[i];
        }

        for(int i = n-2 ; i >= 0 ; i--)
        {
            suff[i] = suff[i+1] * nums[i];
        }
        
        int ans = INT_MIN;
        for(auto it : nums) ans = max(ans , it);
        
        for(int i = 0 , j = n-1 ; i < n && j >= 0 ; i++ , j--)
        {
            ans = max({ans , pref[i] , suff[j]});
        }
    return ans;
    }
};