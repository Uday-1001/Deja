// https://leetcode.com/problems/shifting-letters-ii

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int>shiftings(s.size(),0);

        for(int i = 0; i<shifts.size() ; i++)
        {
            int start = shifts[i][0];
            int end = shifts[i][1];
            int direction = shifts[i][2];

            if(direction == 0)
            {
                shiftings[start] -= 1;
                if(end+1 < shiftings.size())
                {
                    shiftings[end+1] += 1;
                }
            }
            else
            {
                shiftings[start] += 1;
                if(end+1 < shiftings.size())
                {
                    shiftings[end+1] -= 1;
                }
            }
        }

        for(int i = 1 ; i<shiftings.size() ;i++)
        {
            shiftings[i] += shiftings[i-1];
        }

        for(int i = 0 ; i<s.size() ; i++)
        {
            int move = shiftings[i] % 26;
            
            s[i] = 'a' + (s[i] - 'a' + move) % 26;
            
        }
        return s;
    }
};