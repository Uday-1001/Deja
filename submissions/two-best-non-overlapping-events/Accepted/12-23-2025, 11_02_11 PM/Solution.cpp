// https://leetcode.com/problems/two-best-non-overlapping-events

class Solution {
public:    
    int n;
    vector<int>nextevent;
    int byrec(vector<vector<int>>& events , int chose , int i , vector<vector<int>>&dp)
    {
        if(i >= events.size() or chose == 2) return 0;
        if(dp[i][chose] != -1) return dp[i][chose];

        int curr_st = events[i][0];
        int curr_end = events[i][1];
        int points = events[i][2];
        
        int include = points + byrec(events , chose + 1 , nextevent[i] , dp);
        int exclude = 0 + byrec(events , chose , i+1 , dp);

        return dp[i][chose] = max(include , exclude);
    }

    int maxTwoEvents(vector<vector<int>>& events) {
        n = events.size();

        nextevent.resize(n);
        sort(events.begin(), events.end());

        for(int i = 0 ; i<n ; i++)
        {
            int s = i+1;
            int e = n;

            while(s < e)
            {
                int mid = s + (e - s)/2;
                if(events[mid][0] > events[i][1])
                {
                    e = mid;
                }
                else s = mid + 1;
            }
            nextevent[i] = s;
        }

        vector<vector<int>>dp(n+1 , vector<int>(3 , -1));
        return byrec(events , 0 , 0 , dp);
    }
};