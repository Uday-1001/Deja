// https://leetcode.com/problems/valid-parentheses

class Solution {
public:
    bool isValid(string s) {
        vector<char>v;

        for(auto ch : s)
        {
            if(ch == '(' or ch == '{' or ch == '[') v.push_back(ch);
            else if(!v.empty() and v.back() == '{' and ch == '}') v.pop_back();
            else if(!v.empty() and v.back() == '(' and ch == ')') v.pop_back();
            else if(!v.empty() and v.back() == '[' and ch == ']') v.pop_back();
            else return false;
        }
        return v.empty();
    }
};