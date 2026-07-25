// https://leetcode.com/problems/shifting-letters-ii

class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
            char curr_char ;
            int direction ;
            for(int k = 0 ; k < shifts.size(); k++)
            {
                for(int i = shifts[k][0]; i<= shifts[k][1]; i++)
                {
                   direction = shifts[k][2]; 
                   curr_char = s[i];
                   if(direction == 1)
                    {
                        s[i] = (curr_char == 'z') ? 'a' : curr_char + 1;
                    }
                   else
                    {
                        s[i] = (curr_char == 'a') ? 'z' : curr_char - 1;
                    }    
                }
            }
        return s; 
    }
};