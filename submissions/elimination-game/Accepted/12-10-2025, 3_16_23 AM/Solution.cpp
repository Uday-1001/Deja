// https://leetcode.com/problems/elimination-game

class Solution {
public:
    int lastRemaining(int n) {
        int start = 1;
        int steps = 1;
        bool left = true;

        while(n > 1)
        {
            if(left or (n & 1)) start += steps;
            n /= 2;
            steps *= 2;
            left = !left;
        }
    return start;
    }
};