// https://leetcode.com/problems/maximize-area-of-square-hole-in-grid

class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int n = hBars.size();
        int m = vBars.size();
        sort(hBars.begin() , hBars.end());
        sort(vBars.begin() , vBars.end());

        int consecheight = 0;
        int consecwidth = 0;
        for(int i = 1 ; i<n ; i++)
        {
            if(vBars[i] > vBars[i-1]) consecheight++;
            else consecheight = 0;
        }

    }
};