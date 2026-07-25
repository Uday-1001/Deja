// https://leetcode.com/problems/minimum-time-visiting-all-points

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size();
        int time = 0;

        for(int i = 0 ; i<n-1 ; i++)
        {
            auto curr_pt = points[i];
            auto next_pt = points[i+1];

            int req_time_in_x = abs(next_pt[0] - curr_pt[0]);
            int req_time_in_y = abs(next_pt[1] - curr_pt[1]);

            int for_diagonal = min(req_time_in_x , req_time_in_y);
            time += for_diagonal;

            req_time_in_x -= for_diagonal;
            req_time_in_y -= for_diagonal;

            if(req_time_in_x > 0) time += req_time_in_x;
            if(req_time_in_y > 0) time += req_time_in_y;
        }
    return time;
    }
};