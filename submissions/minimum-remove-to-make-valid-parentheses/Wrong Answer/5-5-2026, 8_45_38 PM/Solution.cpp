// https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string str = "";
        int open = 0;

        for(auto ch : s)
        {
            if(ch == '(') 
            {
                open++;
                str.push_back(ch);
            }
            else if(ch == ')')
            {
                if(open == 0) continue;
                else 
                {
                    open--;
                    str.push_back(ch);
                }
            }
            else str.push_back(ch);
        }
        
        int alpha = 0;
        for(auto it : str) if(isalpha(it)) alpha++;
        if(alpha == 0) return "";
        return str;
    }
};