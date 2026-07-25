// https://leetcode.com/problems/interval-list-intersections

class Solution {
public:
    static bool mycomp(const pair<int,int>&a , const pair<int,int>&b)
    {
        if(a.first == b.first) return a.second > b.second;
        return a.first < b.first;
    }

    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>>ans;
        vector<pair<int,int>>events;
        for(auto it : firstList)
        {
            int st = it[0];
            int end = it[1];
            events.push_back({st , +1});
            events.push_back({end , -1});
        }
        for(auto it : secondList)
        {
            int st = it[0];
            int end = it[1];
            events.push_back({st , +1});
            events.push_back({end , -1});
        }

        sort(events.begin() , events.end() , mycomp);

        int sum = 0;
        int start_pt = 0;
        int end_pt = 0;
        bool gotstart = false;

        for(auto it : events)
        {
            auto[pt , delta] = it;
            sum += delta;
            if(sum == 2) 
            {
                start_pt = pt;
                gotstart = true;
            }
            if(sum == 1 and gotstart)
            {
                end_pt = pt;
                gotstart = true;
            }
            if(start_pt > 0 and end_pt > 0)
            {
                ans.push_back({start_pt , end_pt});
                start_pt = 0;
                end_pt = 0;
                gotstart = false;
            } 
        }
    return ans;
    }
};