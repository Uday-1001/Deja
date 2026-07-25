// https://leetcode.com/problems/longest-palindromic-substring

class Solution {
public:
    string ExpandAroundCentre( string &s , int i , int j)
    {
        while(i>=0 && j<s.size() && s[i]==s[j])
        {
            i--;
            j++;
        }
    return s.substr(i+1 , j-i-1);
    }
    string longestPalindrome(string s) {
        string longest = "";
        for(int i =0 ; i<s.size() ; i++)
        {
            string odd_substrs = ExpandAroundCentre(s, i , i);

            if(odd_substrs.size() > longest.size())
            longest = odd_substrs;

            string even_substrs = ExpandAroundCentre(s, i , i+1);

            if(even_substrs.size() > longest.size())
            longest = even_substrs;
        }
    return longest;
    }
};