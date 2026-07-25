// https://leetcode.com/problems/minimum-total-cost-to-process-all-elements

class Solution {
public:
    using ll = long long;
    int mod = 1e9+7;

    ll calculateCost(ll oprs, ll count)
    {
        ll temp = (count % mod) * ((2 * oprs + count + 1) % mod);
        temp /= 2;
        return temp % mod;
    }
    
    int minimumCost(vector<int>& nums, int k) {
        ll ans = 0;
        ll operations = 0;
        ll resource = k;
        
        for(int i = 0 ; i<nums.size() ; i++){
            if(resource < nums[i]){
                ll need = nums[i] - resource;
                ll countofoprs = (need + k -1)/k;
                ans = (ans + calculateCost(operations , countofoprs)) % mod;

                operations += countofoprs;
                resource += (countofoprs * k * 1LL);
            }
            resource -= nums[i];
        }
        return ans;
    }
};