// https://leetcode.com/problems/palindrome-number

class Solution {
public:
    bool isPalindrome(int x) {
        int y=x;
        int rev=0;
        if(x<0)
        return false;
        while(x!=0)
        {
            int digit=x%10;
             rev=(rev*10)+digit;
            x=x/10;
        }
        if(rev==y)
        return true ;
        else 
        return false;
    }
    
};