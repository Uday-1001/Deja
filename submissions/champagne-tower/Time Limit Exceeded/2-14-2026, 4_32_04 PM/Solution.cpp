// https://leetcode.com/problems/champagne-tower

class Solution {
public:
    double byrec(int poured, int i , int j)
    {
        //base case
        if(i < 0 or j < 0) return 0.0;
        if(i == 0 and j == 0) return poured;

        //ek case hum solve karenge
        double left_glass = (byrec(poured , i-1 , j-1) - 1) / 2.0;
        double right_glass = (byrec(poured , i-1 , j) - 1) / 2.0;

        if(left_glass < 0) left_glass = 0.0;
        if(right_glass < 0) right_glass = 0.0;

        return left_glass + right_glass;
    }

    double champagneTower(int poured, int query_row, int query_glass) {
        return min(1.0 , byrec(poured , query_row , query_glass));
    }
};