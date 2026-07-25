// https://leetcode.com/problems/count-and-say

class Solution {
public: 
    string aftercounting(string &s)
    {
        int count = 1;
        string ans = "";
        for(int i = 0 ; i+1<s.size() ; i++)
        {
            if(s[i] == s[i+1]) count++;
            else 
            {
                ans += to_string(count);
                ans.push_back(s[i]);
                count = 1;
            }
        }
        ans.push_back(count + '0');
        ans.push_back(s.back());
        return ans;
    }

    string solve(int n)
    {
        if(n == 1) return "1";

        string prev = solve(n-1);
        return aftercounting(prev);
    }

    string countAndSay(int n) {
        return solve(n);
    }
};