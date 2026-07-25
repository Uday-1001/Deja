// https://leetcode.com/problems/minimum-time-visiting-all-points

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size();
        int time = 0;
        for(int i = 0 ; i<n ; i++)
        {
            auto curr = points[i];
            auto next = i+1 < n ? points[i+1] : {0,0};

            int req_time_in_x = abs(next[0] - curr[0]);
            int req_time_in_y = abs(next[1] - curr[1]);

            int for_diagonal = min(req_time_in_x , req_time_in_y);
            count += for_diagonal;

            req_time_in_x -= for_diagonal;
            req_time_in_y -= for_diagonal;

            if(req_time_in_x > 0) count += req_time_in_x;



            
        }
    }
};