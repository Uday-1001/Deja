// https://leetcode.com/problems/two-best-non-overlapping-events

class Solution {
public:
    int byrec(vector<vector<int>>& events , int prev_st , int prev_end , int chose , int i)
    {
        if(i >= events.size() or chose == 2) return 0;

        int curr_st = events[i][0];
        int curr_end = events[i][1];
        int points = events[i][2];

        int include = 0;
        if(prev_end < curr_st)
        {
            include = points + byrec(events , prev_st , curr_end , chose + 1 , i+1);
        }
        int exclude = 0 + byrec(events , prev_st , prev_end , chose , i+1);

        return max(include , exclude);
    }
    int maxTwoEvents(vector<vector<int>>& events) {
        int prev_st = 0;
        int prev_end = 0;
        return byrec(events , prev_st , prev_end , 0 , 0);
    }
};