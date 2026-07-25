// https://leetcode.com/problems/maximum-difference-between-even-and-odd-frequency-i

class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char,int>mpp;

        for(auto ch : s)
        {
            mpp[ch]++;
        }

        int odd = INT_MIN;
        int even = INT_MAX;

        for(auto it: mpp)
        {
            int freq = it.second;

            if(freq & 1) 
                odd = max(odd , freq);
            else
                even = min(even , freq);
        }
    return (odd - even);
    }
};