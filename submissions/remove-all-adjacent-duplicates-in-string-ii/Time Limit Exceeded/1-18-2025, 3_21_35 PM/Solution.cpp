// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii

class Solution {
public:
    bool IsPossible(string &s , int k)
    {
        int count = 1;
        for(int i=0 ; i<s.size()-1; i++)
        {
            if(s[i]==s[i+1]) 
            count ++;
            else
            count = 1;
            if(count == k)
            {
                return true;
            }
        }
    return false;
    }
    string removeDuplicates(string &s, int k) {
        string ans ="";
        for(char ch : s)
        {
            ans += ch;

        if(IsPossible(ans , k))
            {
                ans.erase(ans.size()-k , k);
            }
        }
    return ans;
    }
};