// https://leetcode.com/problems/water-and-jug-problem

class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {
        if(x + y == target) return true;

        int x_need = abs(target - x);
        int y_need = abs(target - y);

        int cap_x = x % target;
        int cap_y = y % target;

        if(x_need + y_need > cap_x + cap_y) return false;
        else return true;
    }
};