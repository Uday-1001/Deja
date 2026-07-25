// https://leetcode.com/problems/process-string-with-special-operations-i

class Solution {
public:
    string processStr(string s) {
        string ans = "";
        bool hasletter = false;

        for(auto ch : s)
        {
            if(isalpha(ch)) 
            {
                ans += ch;
                hasletter = true;
            }
            else if(hasletter and ch == '*') 
            {
                ans.pop_back();
                if(ans.empty()) break;
            }
            else if(hasletter and ch == '#') ans.push_back(ans.back());
            else if(hasletter and ch == '%') reverse(begin(ans) , end(ans));
        }

        return ans;
    }
};