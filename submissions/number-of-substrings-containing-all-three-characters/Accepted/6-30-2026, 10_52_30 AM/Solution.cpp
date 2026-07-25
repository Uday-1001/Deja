// https://leetcode.com/problems/number-of-substrings-containing-all-three-characters

class Solution {
public:
    unordered_map<char,int>mp;
    int SlidingWindow(string &s)
    {
        int l = 0;
        int count = 0;

        for(int r = 0 ; r<s.size() ; r++)
        {
            mp[s[r]]++;
            while(r - l + 1 >= 3 and mp.size() == 3) 
            {
                count += (s.size() - r);
                mp[s[l]]--;
                if(mp[s[l]] == 0) mp.erase(s[l]);
                l++;
            }
        }
        return count;
    }

    int numberOfSubstrings(string s) {
        return SlidingWindow(s);
    }
};