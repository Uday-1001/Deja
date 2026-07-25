// https://leetcode.com/problems/rotate-string

class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        bool ispossible = false;
        while(n--)
        {
            char first = s.front();
            s.erase(s.begin());
            s.push_back(first);
            if(s == goal) ispossible = true;
        }
    return ispossible;
    }
};