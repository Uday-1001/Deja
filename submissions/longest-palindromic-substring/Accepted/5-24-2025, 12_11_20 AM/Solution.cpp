// https://leetcode.com/problems/longest-palindromic-substring

class Solution {
public:
    string ExpandAroundCentre(int i , int j , string s)
    {
        while(i>=0 && j<s.size() && s[i] == s[j])
        {
            i--;
            j++;
        }
        return s.substr(i+1 , j-i-1);
    }

    string longestPalindrome(string s) {
        string longest = "";
        for(int i = 0 ; i<s.size() ; i++)
        {
            string odd = ExpandAroundCentre(i,i,s);
            if(odd.size() > longest.size())
            {
                longest = odd;
            }
            string even = ExpandAroundCentre(i,i+1,s);
            if(even.size() > longest.size())
            {
                longest = even;
            }
        }
    return longest;
    }
};