// https://leetcode.com/problems/the-skyline-problem

class Solution {
public:
    static bool mycomp(const pair<int,int>&a , const pair<int,int>&b)
    {
        if(a.first == b.first) return a.second > b.second;
        return a.first < b.first;
    }

    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>>ans;
        vector<pair<int,int>>events;

        for(auto it : buildings)
        {
            int st = it[0];
            int end = it[1];
            int ht = it[2];
            events.push_back({st , +ht});
            events.push_back({end , -ht});
        }

        sort(events.begin() , events.end() , mycomp);

        int curr_max = 0;
        int prev_max = 0;
        
        for(auto it : events)
        {
            auto[pt , ht] = it;
            if(ht > curr_max)
            {
                curr_max = ht;
                ans.push_back({pt , curr_max});
            } 
            else if((curr_max + ht) == 0)
            {
                ans.push_back({pt , prev_max});
                curr_max = prev_max;
                prev_max = 0;
            } 
            else prev_max = (ht > 0) ? ht : 0;
        }
    
        vector<vector<int>>merged;
        for(auto &p : ans) 
        {
            if(merged.empty() || merged.back()[1] != p[1]) merged.push_back(p);
        }
        return merged;
    }
};