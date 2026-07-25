// https://leetcode.com/problems/maximum-product-subarray

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int>pref(n , 1) , suff(n , 1);
        pref[0] = nums[0];
        suff[n-1] = nums[n-1];

        for(int i = 1 ; i<n ; i++)
        {
            if(nums[i] == 0) pref[i] = 0;
            else pref[i] = (pref[i-1] != 0) ? pref[i-1] * nums[i] : nums[i];
        } 
        for(int i = n-2 ; i>=0 ; i--) 
        {
            if(nums[i] == 0) suff[i] = 0;
            else suff[i] = (suff[i+1] != 0) ? suff[i+1] * nums[i] : nums[i];
        }

        // for(auto it : pref) cout<<it<<" ";
        // cout<<endl;
        // for(auto it : suff) cout<<it<<" ";

        int maxi = INT_MIN;
        for(int i = 0 ; i<n ; i++)
        {
            maxi = max({maxi , pref[i] , suff[i]});
        }
    return maxi;
    }
};