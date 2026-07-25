// https://leetcode.com/problems/process-string-with-special-operations-ii

class Solution {
public:
    char processStr(string s, long long k) {
        string ans = "";
        bool hasletter = false;
        int len = 0;

        for(int i = 0 ; i<s.size() ; i++)
        {
            char ch = s[i];
            if(isalpha(ch)) 
            {
                len++;
                ans += ch;
                hasletter = true;
            }
            else if(hasletter and ch == '*') 
            {
                len--;
                ans.pop_back();
                if(ans.empty()) hasletter = false;
            }
            else if(hasletter and ch == '#') 
            {
                len += ans.size();
                ans += ans;
            }
            else if(hasletter and ch == '%') 
            {
                reverse(begin(ans) , end(ans));
            }
        }
        
        return (ans.empty() or k > len) ? '.' : ans[k];
    }
};