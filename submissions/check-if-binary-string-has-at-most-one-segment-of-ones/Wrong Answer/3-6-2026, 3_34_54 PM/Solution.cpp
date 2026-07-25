// https://leetcode.com/problems/check-if-binary-string-has-at-most-one-segment-of-ones

class Solution {
public:
    bool checkOnesSegment(string s) {
        int one_pos = -1;

        for(int i = 0 ; i<s.size() ; i++)
        {
            if(s[i] == '1') 
            {
                int curr_pos = i;
                if(one_pos != -1 and abs(one_pos - curr_pos) == 1) return true;
                else one_pos = curr_pos;
            }
        }
    return false;
    }
};