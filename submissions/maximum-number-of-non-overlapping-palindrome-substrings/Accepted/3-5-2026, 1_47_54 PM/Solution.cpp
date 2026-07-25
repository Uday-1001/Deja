// https://leetcode.com/problems/maximum-number-of-non-overlapping-palindrome-substrings

class Solution {
public:
    bool isPalindrome(string &s , int i , int j)
    {
        while(i <= j){
            if(s[i] != s[j]) return false;
            else
            {
                i++;
                j--;
            }
        }
    return true;
    }
    
    int fxn(string &s , int k)
    {
        int n = s.size();
        int ans = 0;
        
        for(int i = 0 ; i<n ;)
        {
            if(i + k - 1 < n and isPalindrome(s , i , i+k-1))
            {
                ans++;
                i += k;
            }
            else if(i + k < n and isPalindrome(s , i , i + k))
            {
                ans++;
                i += k+1;
            }
            else i++;
        }

    return ans;
    }

    
    int maxPalindromes(string s, int k) {
        return fxn(s , k);
    }
};