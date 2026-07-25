// https://leetcode.com/problems/sum-of-distances

class Solution {
public:
    using ll = long long; 
    vector<long long> distance(vector<int>& nums) {
        unordered_map<ll , vector<ll>>mp;

        for(int i = 0 ; i<nums.size() ; i++) mp[nums[i]].push_back(i);

        vector<long long>ans(nums.size() , 0);
        for(auto &it : mp)
        {
            auto vec = it.second;
            int m = vec.size();
            if(m == 1) continue;

            vector<ll>pref(m , 0);
            pref[0] = vec[0];
            
            for(int i = 1 ; i<m ; i++) pref[i] = pref[i-1] + vec[i];
            
            ll total = pref[m-1];
            for(int i = 0 ; i<m ; i++)
            {
                ll leftSum = 0;
                if(i > 0) leftSum = pref[i - 1];

                ll rightSum = total - pref[i];

                ll left = (vec[i] * i) - leftSum;
                ll right = rightSum - (vec[i] * (m - i - 1));

                ans[vec[i]] = left + right;
            }
        }
        return ans;
    }
};