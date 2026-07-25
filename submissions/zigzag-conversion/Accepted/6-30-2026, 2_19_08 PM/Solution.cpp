// https://leetcode.com/problems/zigzag-conversion

class Solution {
public:
    string convert(string s, int numRows) {
        string ans = "";
        vector<string>rows(numRows);

        if(numRows == 1) return s; 
        int cyclelength = numRows + (numRows - 2);

        for(int i = 0 ; i<s.size() ; i++)
        {
            int index = i % cyclelength;
            if(index >= numRows) index = cyclelength - index;

            rows[index] += s[i];
        }

        for(auto it : rows) ans += it;
        return ans;
    }
};