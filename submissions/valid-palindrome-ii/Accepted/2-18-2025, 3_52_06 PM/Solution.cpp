// https://leetcode.com/problems/valid-palindrome-ii

class Solution {
public:
    bool IsPalindrome(string &str, int s , int e)
    {
        while(s<=e)
        {
            if(str[s] != str[e])
            {
                return false;
            }
            else
            {
                s++;
                e--;
            }
        }
        return true;
    }

    bool validPalindrome(string s) {
        int i = 0 , j = s.size()-1 ;
       
        while(i <= j)
        {
            if(s[i] == s[j])
            {
                i++;
                j--;
            }
            else
            {
                int i_deletion = IsPalindrome(s , i+1 , j);

                int j_deletion = IsPalindrome(s , i , j-1);

                return i_deletion or j_deletion;
            }
        }
    return true;
    }
};