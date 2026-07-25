// https://leetcode.com/problems/lexicographically-smallest-string-after-deleting-duplicate-characters

class Solution {
public:
    string lexSmallestAfterDeletion(string s) {
        unordered_map<char , int>mp;

        char highest_char = '';
        int max_freq = INT_MIN;
        for(auto ch : s)
        {
            mp[ch]++;
            if(mp[ch] > max_freq)
            {
                highest_char = ch;
                max_freq = mp[ch];
            }
        }
        cout<<highest_char <<"->"<<max_freq<<endl;
            

        string lexi_small = s;

        
        return "";
    }
};