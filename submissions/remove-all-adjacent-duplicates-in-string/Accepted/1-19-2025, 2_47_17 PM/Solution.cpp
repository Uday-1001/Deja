// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string

class Solution {
public:
    string removeDuplicates(string s) {
        string ans ="";
        for(char ch : s)
        {
            if(!ans.empty() && ch == ans.back())
            {
                ans.pop_back();
            }
            else 
            {
                ans.push_back(ch);
            }
        }
    return ans ;
    }
};