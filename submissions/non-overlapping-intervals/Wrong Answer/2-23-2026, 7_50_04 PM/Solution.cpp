// https://leetcode.com/problems/non-overlapping-intervals

class Solution {
public:
    using pi = pair<int,int>;
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        vector<pi>events;
        for(auto it : intervals)
        {
            int st = it[0];
            int end = it[1];

            events.push_back({st , +1});
            events.push_back({end , -1});
        }

        sort(events.begin() , events.end());

        int sum = 0;
        int mini = 0;

        for(auto it : events)
        {
            auto[pt , delta] = it;
            sum += delta;
            if(sum > 1) mini = max(mini , sum-1);
        }
    return mini;
    }
};