// https://leetcode.com/problems/remove-covered-intervals

class Solution {
public:
    static bool mycomp(const vector<int>&a , const vector<int>&b)
    {
        if(a[0] == b[0]) return a[1] > b[1];
        return a[0] < b[0];
    }

    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin() , intervals.end() , mycomp);

        int lowest_st = intervals[0][0];
        int highest_end = intervals[0][1];
        int removals = 0;

        for(int i = 1 ; i<intervals.size() ; i++)
        {
            int st = intervals[i][0];
            int end = intervals[i][1];
            if(st >= lowest_st and end <= highest_end) removals++;
            else
            {
                lowest_st = min(lowest_st , st);
                highest_end = max(highest_end , end);
            }
        }
    return intervals.size() - removals;
    }
};