// https://leetcode.com/problems/process-string-with-special-operations-i

class Solution {
public:
    string processStr(string s) {
        string ans = "";

        for(auto ch : s)
        {
            if(isalpha(ch)) ans += ch;
            else if(ch == '*') 
            {
                ans.pop_back();
                if(ans.empty()) break;
            }
            else if(ch == '#') ans.push_back(ans.back());
            else if(ch == '%') reverse(begin(ans) , end(ans));
        }

        return ans;
    }
};