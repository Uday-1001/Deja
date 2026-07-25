// https://leetcode.com/problems/count-days-without-meetings

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        

        int start = meetings[0][0];
        int end = meetings[0][1];
        int available_days = 0;
        if(meetings.size() == 1)
            {
                available_days = end - start + 1;
            }
            
        for(int i = 1 ; i<meetings.size() ; i++)
        {
            if(end >= meetings[i][0])
            {
                end = max(end , meetings[i][1]);
                start = min(start , meetings[i][0]);
                available_days = end - start + 1;
            }
            else
            {
                available_days += end - start + 1;
                //  cout<<available_days<<" "<<endl;
                end = meetings[i][1];
                start = meetings[i][0];
                if(i == meetings.size()-1)
                {
                    available_days += end- start+1;
                }
                // available_days += end - start + 1;
                // cout<<available_days<<" "<<start<<" "<<end<<endl;
            
            }
        }
        // available_days += end - start + 1;
        // cout<<available_days<<endl;
    return days - available_days;
    }
};