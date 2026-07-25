// https://leetcode.com/problems/maximize-area-of-square-hole-in-grid

class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int x = hBars.size();
        int y = vBars.size();
        sort(hBars.begin() , hBars.end());
        sort(vBars.begin() , vBars.end());

        int consecheight = 1;
        int maxheight = 1;
        int maxwidth = 1;
        int consecwidth = 1;

        for(int i = 0 ; i+1<y ; i++)
        {
            if(vBars.size() == 1) break;
            if(vBars[i+1] - vBars[i] == 1)
            {
                consecheight++;
                maxheight = max(maxheight , consecheight);
            } 
            else consecheight = 1;
        }
        for(int i = 0 ; i+1<x ; i++)
        {
            if(hBars.size() == 1) break;
            if(hBars[i+1] - hBars[i] == 1)
            {
                consecwidth++;
                maxwidth = max(maxwidth , consecwidth);
            } 
            else consecwidth = 1;
        }
        
        int side_req = min(maxwidth , maxheight) + 1;
        return side_req * side_req;
    }
};