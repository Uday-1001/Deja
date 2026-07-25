// https://leetcode.com/problems/merge-close-characters

class Solution {
public:
    string mergeCharacters(string s, int k) {
        unordered_map<char , int>mp;
        string ans = "";

        int index = 0;
        for(int i = 0 ; i<s.size(); i++)
        {
            int curr_pos = index;
            if(mp.count(s[i]))
            {
                int last_pos = mp[s[i]];
                if(curr_pos - last_pos <= k) continue;
            } 
            mp[s[i]] = index;
            index++;
            ans.push_back(s[i]);
        }
    return ans;
    }
};