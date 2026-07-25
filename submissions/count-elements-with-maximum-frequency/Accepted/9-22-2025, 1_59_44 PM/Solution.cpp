// https://leetcode.com/problems/count-elements-with-maximum-frequency

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>mp;

        int total = 0;
        int maxi = 0;

        for(auto x : nums)
        {
            mp[x]++;
        }
        for(auto it : mp)
        {
            if(it.second > maxi)
            {
                maxi = it.second;
            }
        }
        for(auto it : mp)
        {
            if(it.second >= maxi)
            {
                total += it.second;
            }
        }
    return total;
    }
};