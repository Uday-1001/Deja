// https://leetcode.com/problems/longest-palindromic-substring

class Solution {
public:
    string isPalindrome(string &s , int i , int j)
    {
        while(i>=0 && j<s.size() && s[i] == s[j])
        {
            i--;
            j++;
        }
        return s.substr(i+1 , j-i-1);
    }

    string solve(string s)
    {
        string longest = "";
        for(int centre = 0 ; centre < s.size() ; centre++)
        {
            string odd = isPalindrome(s , centre , centre);
            if(longest.size() < odd.size()) longest = odd;

            string even = isPalindrome(s , centre , centre+1);
            if(longest.size() < even.size()) longest = even;
        }
        return longest;
    }

    string longestPalindrome(string s) {
        return solve(s);
    }
};