// https://leetcode.com/problems/minimum-increase-to-maximize-special-indices

class Solution {
public:
    using ll = long long;
    long long minIncrease(vector<int>& nums) {
        int n = nums.size();

        vector<ll>oprs(n , 0);
        for(int i = 1 ; i<n-1 ; i++){
            ll maxi = max(nums[i-1] , nums[i+1]);
            oprs[i] = max(0LL , (maxi + 1 - nums[i]));
        }

        int size = n-2;
        if(size & 1)
        {
            ll ans = 0;
            for(int i = 1 ; i<n-1 ; i+=2){
                ans += oprs[i];
            }
            return ans;
        }
        else
        {
            int k = (size/2);
            vector<ll>firsthalf(k+1 , 0);
            vector<ll>secondhalf(k+1 , 0);
    
            for(int i = 1 ; i<=k ; i++){
                firsthalf[i] = firsthalf[i-1] + oprs[2 * i - 1];
            }

            for(int i = 1 ; i<=k ; i++){
                secondhalf[i] = secondhalf[i-1] + oprs[n - 2 * i];
            }

            ll min_oprs = firsthalf[0] + secondhalf[k];
            for(int i = 1 ; i<=k ; i++){
                min_oprs = min(min_oprs , (firsthalf[i] + secondhalf[k - i]));
            }
            return min_oprs;
        } 
    }
};