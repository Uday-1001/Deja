// https://leetcode.com/problems/maximum-manhattan-distance-after-all-moves

class Solution {
public:
    int maxDistance(string moves) {
        int hori = 0;
        int verti = 0;
        int underscores = 0;

        for(auto move : moves)
        {
            if(move == 'U') verti++;
            else if(move == 'R') hori++;
            else if(move == 'D') verti--;
            else if(move == 'L') hori--;
            else underscores++;
        }
        return abs(hori) + abs(verti) + underscores;
    }
};