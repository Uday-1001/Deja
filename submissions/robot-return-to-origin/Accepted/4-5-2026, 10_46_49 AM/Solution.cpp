// https://leetcode.com/problems/robot-return-to-origin

class Solution {
public:
    bool judgeCircle(string moves) {
        int up = 0;
        int down = 0;
        int left = 0;
        int right = 0;

        int sumuptodown = 0;
        int sumlefttoright = 0;

        for(auto ch : moves)
        {
            if(ch == 'U') sumuptodown++;
            else if(ch == 'D') sumuptodown--;
            else if(ch == 'R') sumlefttoright++;
            else sumlefttoright--;
        }

        return sumuptodown == 0 and sumlefttoright == 0;
    }
};