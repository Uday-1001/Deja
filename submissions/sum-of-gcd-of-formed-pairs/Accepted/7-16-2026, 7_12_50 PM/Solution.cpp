// https://leetcode.com/problems/sum-of-gcd-of-formed-pairs

class Solution {
public:
    using ll = long long;

    long long gcdSum(vector<int>& nums) {
        int n = nums.size();

        vector<ll>pref(n);
        pref[0] = nums[0];

        ll maxi = nums[0];

        for(int i = 1 ; i<n ; i++) 
        {
            maxi = max(maxi , (ll)nums[i]);
            pref[i] = gcd(maxi , (ll)nums[i]);
        }

        sort(begin(pref) , end(pref));

        ll sum = 0;
        for(int i = 0 , j = n-1 ; i<j ; i++ , j--)
        {
            sum += (gcd(pref[i] , pref[j]));
        }
        return sum;
    }
};