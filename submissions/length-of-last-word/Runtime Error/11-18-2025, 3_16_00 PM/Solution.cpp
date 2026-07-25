// https://leetcode.com/problems/length-of-last-word

class Solution {
public:
    int lengthOfLastWord(string s) {
        int i = s.size()-1;
        int count = 0;
        if(s.size() == 1) return 1;
        while(true)
        {
            while(s[i] == ' ') i--;

            while(isalpha(s[i]))
            {
                count++;
                i--;
            }
            if(s[i] == ' ') break;
        }
    return count;
    }
};