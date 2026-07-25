// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii

class Solution {
public:
    bool IsPossible(string &s , int k)
    {
        for(int i=s.length()-1 ; i>=s.length()-k+1; i--)
        {
            if(s[i] != s[i-1])
            {
                return false;
            } 
        }
    return true;
    }
    string removeDuplicates(string &s, int k) {
    string ans ="";
    for(char ch : s)
    {
        ans += ch;
        if(ans.size() >= k)
        {
            if(IsPossible(ans , k))
            {
                ans.erase(ans.size()-k , k);
            }
        }
    }
    return ans;
    }
};