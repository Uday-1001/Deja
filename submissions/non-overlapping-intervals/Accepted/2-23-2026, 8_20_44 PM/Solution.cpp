// https://leetcode.com/problems/non-overlapping-intervals

class Solution {
public:
    static bool mycomp(const vector<int>&a , const vector<int>&b)
    {
        if(a[1] == b[1]) return a[0] < b[0];
        return a[1] < b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin() , intervals.end() , mycomp);

        int ans = 0;

        int prevst = intervals[0][0];
        int prevend = intervals[0][1];

        for(int i = 1 ; i<intervals.size() ; i++)
        {
            int currst = intervals[i][0];
            int currend = intervals[i][1];

            if(currst < prevend)
            {
                ans++;
            }
            else
            {
                prevend = currend;
            }
        }
    return ans;
    }
};