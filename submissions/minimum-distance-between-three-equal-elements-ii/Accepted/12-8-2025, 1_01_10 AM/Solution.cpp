// https://leetcode.com/problems/minimum-distance-between-three-equal-elements-ii

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>>mp;
        for(int i =0 ; i<nums.size() ; i++)
        {
            mp.push_back({nums[i] , i});
        }

        sort(mp.begin() , mp.end());

        int ans = INT_MAX;
        
        for(int i=0 ; i < n-2 ; i++)
        {
            if(mp[i].first == mp[i+1].first and mp[i+1].first == mp[i+2].first)
            {
                int d1 = mp[i].second;
                int d2 = mp[i+1].second;
                int d3 = mp[i+2].second;

                int distance = abs(d1 - d2) + abs(d2 - d3) + abs(d3 - d1);
                ans = min(ans , distance);
            } 
        }
        return ans == INT_MAX ? -1 : ans;
    }
};