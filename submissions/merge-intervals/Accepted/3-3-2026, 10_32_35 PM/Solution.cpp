// https://leetcode.com/problems/merge-intervals

class Solution {
public:
    using pi = pair<int,int>;

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<pi>events;
        for(auto it : intervals)
        {
            auto st = it[0];
            auto end = it[1];
            events.push_back({st , +1});
            events.push_back({end , -1});
        }

        sort(events.begin() , events.end() , [](pair<int,int>&p1 , pair<int,int>&p2){
            if(p1.first == p2.first) return p1.second > p2.second;
            return p1.first < p2.first;
        });

        int sum = 0;
        int stpt = -1;
        int endpt = -1;
        vector<vector<int>>ans;
    
        for(auto it : events)
        {
            auto[pt , delta] = it;
            sum += delta;

            if(sum == 1 and stpt == -1)
            {
                stpt = pt;
            }
            if(sum == 0)
            {
                endpt = pt;
                if(stpt != -1 and endpt != -1) ans.push_back({stpt , endpt});
                endpt = -1;
                stpt = -1;
            }
        }
    return ans;
    }
};