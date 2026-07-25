// https://leetcode.com/problems/find-the-largest-area-of-square-inside-two-rectangles

class Solution {
public:
    int getmaxside(vector<int>&bl , vector<int>&tr)
    {
        int x1 = bl[0] , x2 = tr[1];
        int x3 = bl[0] , x4 = tr[1];
    }

    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n = bottomLeft.size();
        int maxside = 0;
        for(int i = 0 ; i<n ; i++)
        {
            for(int j = i+1 ; j<n ; j++)
            {
                int first = getmaxside(bottomLeft[i] , topRight[i]);
            }
        }
    }
};