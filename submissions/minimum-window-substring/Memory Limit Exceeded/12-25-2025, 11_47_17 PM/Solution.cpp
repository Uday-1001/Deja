// https://leetcode.com/problems/minimum-window-substring

class Solution {
public:
    string minWindow(string s, string t) {
        int count_req = t.size();

        unordered_map<char,int>mp;
        for(auto ch : t) mp[ch]++;

        int l = 0;
        string ans = "";

        for(int r = 0 ; r < s.size() ; r++)
        {
            if(mp[s[r]] > 0) count_req--;
            mp[s[r]]--;

            while(count_req == 0)
            {
                if(ans.empty() or ans.size() > r - l + 1) ans = s.substr(l, r - l + 1);

                char left_char = s[l];
                mp[left_char]++;
                if(mp[left_char] > 0) count_req++;
                l++;
            }
        }
    return ans;
    }
};