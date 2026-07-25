// https://leetcode.com/problems/generate-parentheses

class Solution {
public:
    void solve(int n , vector<string>&ans , string &output , int open , int close )
    {
        //base case
        if(open + close == 2*n)
        {
            ans.push_back(output);
            return;
        }
        //hume pehle open ko exhaust karna hai ki saari string valid mile 
        if(open < n)
        {
            output.push_back('(');
            //recursive call
            solve(n , ans , output , open + 1 , close);
            //backtracking karna agar function se return hota hai to 
            output.pop_back();
        }
        // yha hum log close ki call denge tab jab open khatam honge aur humare close he sirf baaki honge 
        if(close < open)
        {
            output.push_back(')');
            //recursive call
            solve(n , ans , output , open , close + 1);
            //backtracking karna agar function se return hota hai to 
            output.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string output = "";

        solve(n , ans , output , 0 , 0);
        return ans;
    }
};