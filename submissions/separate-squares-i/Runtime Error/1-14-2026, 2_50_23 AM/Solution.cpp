// https://leetcode.com/problems/separate-squares-i

class Solution {
public:
    double checkmid(vector<vector<int>>& squares , double mid)
    {
        double bottomarea = 0;
        double toparea = 0;
        for(auto &square : squares)
        {
            int boty = square[1];
            int side = square[2];
            int topy = boty + side;

            if(mid >= topy) bottomarea += (side * side);
            else if(mid <= boty) toparea += (side * side);
            else
            {
                toparea += (topy - mid) * side;
                bottomarea += (mid - boty) * side;
            }
        }
    return bottomarea - toparea;
    }

    double separateSquares(vector<vector<int>>& squares) {
        int maxy = INT_MIN;
        for(auto &square : squares)
        {
            maxy = max(maxy , square[1] + square[2]);
        }
        
        double s = 0;
        double e = maxy;
        double ans = -1;

        while(e - s > 1e-5)
        {   
            double mid = s + (e-s)/2.0;
            
            double diff = checkmid(squares , mid);
            if(diff >= 0)
            {
                ans = mid;
                e = mid;
            } 
            else s = mid;
        }
    return ans;
    }
};