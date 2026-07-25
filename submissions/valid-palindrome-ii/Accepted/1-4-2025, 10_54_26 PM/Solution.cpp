// https://leetcode.com/problems/valid-palindrome-ii

class Solution {
public:
    bool checkPalindrome(string s , int i ,int j){
        while(i<=j){
            if(s[i] != s[j])
            {
                return false;
            }
            else
            {
                i++;
                j--;
            }
        }
        return true;
    }
    bool validPalindrome(string s) {
        int i=0;
        int j=s.length()-1;
        while(i<=j){
            if(s[i] == s[j])
            {
                i++;
                j--;
            }
            else
            {
                bool ideletion = checkPalindrome(s , i+1 ,j);
                bool jdeletion = checkPalindrome(s , i , j-1);

                return  ideletion || jdeletion ;  
            }
        }
        return true ;
    }
};