// https://leetcode.com/problems/merge-intervals

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        vector<pair<int, int>>vp;

        for(auto &it : intervals)
        {
            int u = it[0];
            int v = it[1];

            vp.push_back({u, +1});
            vp.push_back({v, -1});
        }

        sort(vp.begin(), vp.end(), [](const pair<int, int>&a, const pair<int, int>&b){
            if(a.first == b.first) return b.second < a.second;
            return a.first < b.first;
        });

        int start = -1;
        int end = -1;
        int sum = 0;
        
        for(auto it : vp)
        {
            int pt = it.first;
            int delta = it.second;
            
            sum += delta;
            
            if(sum == 1 and start == -1) start = pt;
            
            if(sum == 0) end = pt;
            
            if(start != -1 and end != -1) 
            {
                ans.push_back({start , end});
                start = -1;
                end = -1;
            }
        }
        
        return ans;
    }
};