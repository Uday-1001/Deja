// https://leetcode.com/problems/valid-palindrome

class Solution {
public:
    bool isPalindromeCheck(string &str)
    {
        int i = 0 , j = str.size() - 1;
        while(i < str.size() && j >= 0)
        {
            if(str[i] != str[j]) return false;
            else
            {
                i++; j--;
            }
        }
        return true;
    }
    bool isPalindrome(string s) {
        int n = s.size();
        string new_s = "";
        for(int i = 0 ; i<n ; i++)
        {
            if(!(islower(s[i]) or isupper(s[i]))) continue;
            new_s.push_back(tolower(s[i]));
        }
        if(new_s.empty()) return true;
        return isPalindromeCheck(new_s);
    }
};