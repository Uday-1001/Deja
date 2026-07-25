// https://leetcode.com/problems/remove-covered-intervals

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(begin(intervals) , end(intervals) , [](vector<int>&a , vector<int>&b)
        {   
            if(a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });

        int lowest_st = -1;
        int lowest_end = -1;
        int removals = 0;

        for(auto it : intervals)
        {
            int st = it[0];
            int end = it[1];

            if(lowest_st == -1 and lowest_end == -1)
            {
                lowest_st = st;
                lowest_end = end;
            }
            else if(st >= lowest_st and end <= lowest_end) removals++;
            else
            {
                lowest_st = min(lowest_st , st);
                lowest_end = max(lowest_end , end);
            }
        }
        return (intervals.size() - removals);
    }
};