// https://leetcode.com/problems/remove-covered-intervals

class Solution {
public:
    using pi = pair<int,int>;

    int LineSweep(vector<vector<int>>& intervals)
    {
        vector<pi> events;
        vector<pi> ans;

        for(auto &it : intervals)
        {
            int st = it[0];
            int end = it[1];

            events.push_back({st, +1});
            events.push_back({end, -1});
        }

        sort(begin(events), end(events), [](const pi &a, const pi &b){
            if(a.first == b.first) return a.second > b.second;
            return a.first < b.first;
        });

        int sum = 0;
        int startpt = -1;

        for(auto &it : events)
        {
            auto [pt, delta] = it;

            if(sum == 0) startpt = pt;

            sum += delta;

            if(sum == 0) ans.push_back({startpt, pt});
        }

        return intervals.size() - ans.size();
    }

    int removeCoveredIntervals(vector<vector<int>>& intervals)
    {
        return LineSweep(intervals);
    }
};