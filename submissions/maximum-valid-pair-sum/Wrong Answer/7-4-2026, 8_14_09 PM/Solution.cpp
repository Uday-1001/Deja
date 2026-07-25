// https://leetcode.com/problems/maximum-valid-pair-sum

class Solution {
public:
    using ll = long long;
    int maxValidPairSum(vector<int>& nums, int k) {
        vector<pair<int,int>>vp;
        for(int i = 0 ; i<nums.size() ; i++){
            vp.push_back({nums[i] , i});
        }

        long long maxsum = LLONG_MIN;
        sort(rbegin(vp) , rend(vp));

        for(int i = 0 ; i+1<vp.size() ; i++){
           for(int j = i+1 ; j<vp.size() ; j++){
               if(vp[i].second - vp[j].second >= k){
                   maxsum = max(maxsum , (ll)((ll)vp[i].first + (ll)vp[j].first));
               }
           }
        }

        return maxsum;
    }
};