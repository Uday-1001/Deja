// https://leetcode.com/problems/angle-between-hands-of-a-clock

class Solution {
public:
    double angleClock(int hour, int minutes) {
        if(hour == 12) hour = 0;
        return(abs(((double)minutes * 5.5) - 30 * hour));
    }
};