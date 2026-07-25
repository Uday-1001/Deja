// https://leetcode.com/problems/maximum-product-subarray

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int>pref(n , 1) , suff(n , 1);
        pref[0] = nums[0];
        suff[n-1] = nums[n-1];

        for(int i = 1 ; i<n ; i++) pref[i] = pref[i-1] * nums[i];
        for(int i = n-2 ; i>=0 ; i--) suff[i] = suff[i+1] * nums[i];

        int maxi = INT_MIN;
        for(int i = 0 ; i<n ; i++)
        {
            maxi = max({maxi ,pref[i] , suff[i]});
        }
    return maxi;
    }
};