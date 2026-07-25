// https://leetcode.com/problems/find-the-largest-area-of-square-inside-two-rectangles

class Solution {
public:
    int getmaxside(vector<int>&bl1 , vector<int>&tr1 , vector<int>&bl2 , vector<int>&tr2)
    {
        int intersect_xb = max(bl1[0], bl2[0]);
        int intersect_yb = max(bl1[1], bl2[1]);

        int intersect_xu = min(tr1[0], tr2[0]);
        int intersect_yu = min(tr1[1], tr2[1]);

        int overlapW = intersect_xu - intersect_xb;
        int overlapH = intersect_yu - intersect_yb;

        if(overlapW <= 0 or overlapH <= 0) return 0;
        return min(overlapW, overlapH);
    }

    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n = bottomLeft.size();
        int maxside = 0;
        for(int i = 0 ; i<n ; i++)
        {
            for(int j = i+1 ; j<n ; j++)
            {
                int side = getmaxside(bottomLeft[i] , topRight[i] , bottomLeft[j] , topRight[j]);
                maxside = max(maxside , side);
            }
        }
    return 1LL * maxside * maxside;
    }
};