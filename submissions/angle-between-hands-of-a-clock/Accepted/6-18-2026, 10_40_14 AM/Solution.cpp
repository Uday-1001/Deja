// https://leetcode.com/problems/angle-between-hands-of-a-clock

class Solution {
public:
    double angleClock(int hour, int minutes) {
        double ans = 0.0;
        if(hour == 12) hour = 0;
        double hourangle = hour * 30.0 + (((double)minutes / 60.0) * 30.0);

        double minuteangle = minutes * 6.0;

        ans = abs(minuteangle - hourangle);
        return min(ans , 360.0 - ans);
    }
};