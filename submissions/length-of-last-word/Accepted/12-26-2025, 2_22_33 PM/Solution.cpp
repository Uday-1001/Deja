// https://leetcode.com/problems/length-of-last-word

class Solution {
public:
    void rtrim(string &s) 
    {
        while(!s.empty() && s.back() == ' ') s.pop_back();
    }
    
    int lengthOfLastWord(string s) {
        rtrim(s);
        reverse(s.begin() , s.end());
        int last_space_index = s.find(' ');
        return s.substr(0 , last_space_index).size();
    }
};