// https://leetcode.com/problems/k-closest-points-to-origin

class Solution {
public:
    #define pi pair<int,int>

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>ans;
        priority_queue<pi , vector<pi> , greater<pi>>pq;

        for(int i=0 ; i<points.size() ; i++)
        {
            vector<int> point = points[i];
            long long x_cord = point[0];
            long long y_cord = point[1];

            long long calculated_distance_square = (x_cord * x_cord) + (y_cord * y_cord);

            pq.push({calculated_distance_square , i});
        }

        while(!pq.empty() && k--)
        {
            auto nearest_pt_index = pq.top().second;
            pq.pop();
            ans.push_back(points[nearest_pt_index]);
        }

        return ans;
    }
};