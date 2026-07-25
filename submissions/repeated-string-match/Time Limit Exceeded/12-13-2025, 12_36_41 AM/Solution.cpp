// https://leetcode.com/problems/repeated-string-match

class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int repetitions = 0;
        string testing = "";
        while(true)
        {
            testing += a;
            repetitions++;
            if(testing.find(b) != string::npos) break;    
        }
        return repetitions;
    }
};