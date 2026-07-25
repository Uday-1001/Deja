// https://leetcode.com/problems/smallest-subsequence-of-distinct-characters

class Solution {
public:
    string smallestSubsequence(string s) {
        string ans = "";

        vector<int>lastoccurence(26 , 0);
        vector<bool>vis(26 , false);

        for(int i = 0 ; i<s.size() ; i++) lastoccurence[s[i] - 'a'] = i;

        for(int i = 0 ; i<s.size() ; i++)
        {
            if(vis[s[i] - 'a']) continue;

            while(!ans.empty() and ans.back() > s[i] and lastoccurence[ans.back() - 'a'] > i)
            {
                vis[ans.back() - 'a'] = false;
                ans.pop_back();
            }

            ans.push_back(s[i]);
            vis[s[i] - 'a'] = true;
        }

        return ans;
    }
};