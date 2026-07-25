// https://leetcode.com/problems/longest-palindromic-substring

class Solution {
public:

    string longest = "";

    string ExpandAroundCentre(string &s , int i , int j)
    {
        while(i>=0 && j<s.size() && s[i] == s[j])
        {
            i--;
            j++;
        }
        return s.substr(i+1 , j-i-1);
    }
    string longestPalindrome(string s) {

        for(int i = 0; i <s.size() ; i++)
        {
            string odd_substr = ExpandAroundCentre(s , i , i);

            if(odd_substr.size() > longest.size())
            longest = odd_substr;

            string even_substr = ExpandAroundCentre(s , i , i+1);

            if(even_substr.size() > longest.size())
            longest = even_substr;
        }
    return longest;
    }
};