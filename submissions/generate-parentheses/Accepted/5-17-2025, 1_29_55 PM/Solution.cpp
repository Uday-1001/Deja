// https://leetcode.com/problems/generate-parentheses

class Solution {
public:
    void solve(int n , vector<string>&ans , int open , int close , string &output)
    {   
        if(open + close == 2*n)
        {
            ans.push_back(output);
            return;
        }

        if(open < n)
        {
            output.push_back('(');

            solve(n , ans , open+1 , close , output);
            //backtracking
            output.pop_back();
        }
        if(close < open)
        {
            output.push_back(')');

            solve(n , ans , open , close+1 , output);
            //backtracking
            output.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string output = "";

        int open = 0;
        int close = 0;

        solve(n , ans , open , close , output);
        return ans;
    }
};