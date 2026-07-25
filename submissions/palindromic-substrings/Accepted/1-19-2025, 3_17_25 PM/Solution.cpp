// https://leetcode.com/problems/palindromic-substrings

class Solution {
public:
    int ExpandAroundCentre(string &s , int i , int j)
    {
        int count = 0;
        while(i>=0 && j<s.size() && s[i] == s[j])
        {
            count ++;
            i--;
            j++;
        }
    return count ;
}
    
    int countSubstrings(string s) {
    int total =0;
    for(int i =0 ; i < s.size() ; i++)
    {
        total += ExpandAroundCentre(s,i,i);

        total += ExpandAroundCentre(s,i,i+1);
    }
    return total;
    }
};