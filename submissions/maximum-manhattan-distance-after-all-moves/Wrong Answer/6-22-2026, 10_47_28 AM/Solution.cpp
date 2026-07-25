// https://leetcode.com/problems/maximum-manhattan-distance-after-all-moves

class Solution {
public:
    int maxDistance(string moves) {
        int upandright = 0;
        int downandleft = 0;
        int underscores = 0;

        for(auto move : moves)
        {
            if(move == 'U') upandright++;
            if(move == 'R') upandright++;
            if(move == 'D') downandleft++;
            if(move == 'L') downandleft++;
            if(move == '_') underscores++;
        }
        return abs(upandright - downandleft) + underscores;
    }
};