// https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string

class Solution {
public:
    string removeDuplicates(string s) {
        string ans = "";

        for(int i = 0; i<s.size() ; i++)
        {
            char curr_char = s[i];
            if(ans.empty() or curr_char != ans.back())
            {
                ans.push_back(curr_char);
            }
            else if(curr_char == ans.back())
            {
                ans.pop_back();
            } 
        }
    return ans;
    }
};