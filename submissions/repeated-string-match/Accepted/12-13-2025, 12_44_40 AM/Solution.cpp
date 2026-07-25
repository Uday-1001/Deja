// https://leetcode.com/problems/repeated-string-match

class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        int ans = -1;
        int repetitions = 0;
        string testing = "";
        while(true)
        {
            testing += a;
            repetitions++;
            if(testing.find(b) != string::npos)
            {
                ans = repetitions;
                break;
            }   
            else if(testing.find(b) == string::npos)
            {
                if(repetitions > (b.size()/a.size() + 1)) break;
            }
        }
        return ans;
    }
};