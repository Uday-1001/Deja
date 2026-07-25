// https://leetcode.com/problems/longest-palindromic-substring

class Solution {
public:

    string ExpandAroundCentre(string &s , int i , int j){
        
        while(i>=0 && j<s.size() && s[i] == s[j])
            {
                i--;
                j++;
            }
            // kyuki i-- ek peeche krdega aur j++ ek aage krdega pointers ke position ko
        return s.substr(i+1,j-i-1) ;
        }

    string longestPalindrome(string s) {
        string longest_string;
        for(int centre =0 ; centre< s.size(); centre++)
        {   
            string odd_substrs = ExpandAroundCentre(s,centre,centre);
            if(odd_substrs.length() > longest_string.length())
            {
                longest_string = odd_substrs;
            }

            string even_substrs = ExpandAroundCentre(s,centre,centre+1);
            if(even_substrs.length() > longest_string.length())
            {
                longest_string = even_substrs;
            }
        }
    return longest_string;
    }
};