// https://leetcode.com/problems/maximum-score-of-a-split

class Solution {
public:
    using ll = long long;
    long long maximumScore(vector<int>& nums) {
        int n = nums.size();
        vector<ll>prefix(n , 0);
        vector<ll>suffix(n , 0);

        prefix[0] = nums[0];
        suffix[n-2] = nums[n-1];

        for(int i = 1 ; i<n ; i++)
        {
            prefix[i] = prefix[i-1] + nums[i];
        }

        for(int i = n-3 ; i>=0 ; i--)
        {
            suffix[i] = min<ll>(suffix[i+1] , nums[i+1]);
        }

        ll maxi = INT_MIN;
        for(int i = 0; i<n-1 ; i++)
        {
            maxi = max<ll>(maxi , prefix[i] - suffix[i]);
        }
    return maxi;
    }
};