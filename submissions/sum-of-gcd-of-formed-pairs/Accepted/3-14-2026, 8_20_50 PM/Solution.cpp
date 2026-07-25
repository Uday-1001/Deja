// https://leetcode.com/problems/sum-of-gcd-of-formed-pairs

class Solution {
public:
    using ll = long long;
    
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<ll>pref(n , 0);
        int maxi = INT_MIN;

        for(int i = 0 ; i<n ; i++){
            maxi = max(maxi , nums[i]);
            pref[i] = gcd(nums[i] , maxi);
        }

        sort(begin(pref) , end(pref));

        ll ans = 0;
        int l = 0;
        int r = n-1;

        while(l < r){
            ans += gcd(pref[l] , pref[r]);
            l++;
            r--;
        }
    return ans;
    }
};