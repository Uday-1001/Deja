// https://leetcode.com/problems/remove-outermost-parentheses

class Solution {
public:
    string removeOuterParentheses(string s) {
        int count_open = 0;
        string result = "";

        for(auto ch : s)
        {
           if(ch == '(')
            {
                count_open++;
                if(count_open > 1) result += ch;
            }
            else if(ch == ')')
            {
                count_open--;
                if(count_open > 0) result += ch;
            } 
        }
    return result;
    }
};