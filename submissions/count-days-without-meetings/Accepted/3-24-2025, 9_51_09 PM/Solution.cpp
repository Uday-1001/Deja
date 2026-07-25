// https://leetcode.com/problems/count-days-without-meetings

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin() , meetings.end());
        int start = 0;
        int end  = 0;
        int offdays = 0;

        for(int i=0 ;i<meetings.size(); i++)
        {
            int next_start_time = meetings[i][0];
            int next_end_time = meetings[i][1];

            if(next_start_time > end)
            {
                offdays += next_start_time - end - 1;
            }
            end = max(end , next_end_time);
        }
        if(days > end)
        {
            offdays += days - end;
        }
    return offdays;
    }
};