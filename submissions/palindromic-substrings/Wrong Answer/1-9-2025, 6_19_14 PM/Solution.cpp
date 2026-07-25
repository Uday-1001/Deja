// https://leetcode.com/problems/palindromic-substrings

class Solution {
public:

    int ExpandAroundCentre(string &s , int i , int j){
        int count = 0;
        // means yha tak palindrome hai
        while(i>=0 && j<s.length() && s[i] == s[j])
        {
            count++;
            // kyuki expand krna hai to i-- aur j++ krna hoga 
            i--;
            j++;
        }
        return count;
    }

    int countSubstrings(string s) {
        int total_substrings = 0;
        
        for(int centre =0 ; centre <s.length(); centre ++)
        {
            int i = centre;
            int j = centre;

            int odd_substrings = ExpandAroundCentre(s , i , j);

            i = centre ;
            j = centre +1;
            
            int even_substrings = ExpandAroundCentre(s , i , j);

            total_substrings = odd_substrings + even_substrings;
        }
        return total_substrings;
    }
};