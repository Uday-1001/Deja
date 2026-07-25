// https://leetcode.com/problems/rotate-string

class Solution {
public:
    bool rotateString(string s, string goal) {
        string twice = s+s;
        
        for(int i = 0 ; i<twice.size()-s.size() ; i++)
        {
            string str = twice.substr(i , s.size());
            if(str == goal) return true;
        }
        return false;
    }
};