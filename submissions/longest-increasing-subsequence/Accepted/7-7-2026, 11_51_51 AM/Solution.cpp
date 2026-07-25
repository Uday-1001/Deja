// https://leetcode.com/problems/longest-increasing-subsequence

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>longestchain;

        for(auto it : nums)
        {
            auto nextnumber_idx = lower_bound(begin(longestchain) , end(longestchain) , it);

            if(nextnumber_idx == longestchain.end()) longestchain.push_back(it);
            else *nextnumber_idx = it;
        }
        return longestchain.size();
    }
};