// https://leetcode.com/problems/process-string-with-special-operations-i

class Solution {
public:
    string processStr(string s) {
        string ans = "";
        bool hasletter = false;

        for(int i = 0 ; i<s.size() ; i++)
        {
            char ch = s[i];
            if(isalpha(ch)) 
            {
                ans += ch;
                hasletter = true;
            }
            else if(hasletter and ch == '*') 
            {
                ans.pop_back();
                if(ans.empty()) hasletter = false;
            }
            else if(hasletter and ch == '#') 
            {
                ans += ans.substr(0 , i);
            }
            else if(hasletter and ch == '%') 
            {
                reverse(begin(ans) , end(ans));
            }
        }

        return ans;
    }
};