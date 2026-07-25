// https://leetcode.com/problems/maximum-substrings-with-distinct-start

class Solution {
public:
    int maxDistinct(string s) {
       unordered_map<char,bool>mp;
        int ans = 0;
        for(auto ch : s){
            if(mp.find(ch) == mp.end())
            {
                mp[ch] = true;
                ans++;
            }
        }
        return ans;
    }
};