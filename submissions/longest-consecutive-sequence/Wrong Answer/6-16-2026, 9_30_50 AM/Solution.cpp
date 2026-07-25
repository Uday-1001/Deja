// https://leetcode.com/problems/longest-consecutive-sequence

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int maxlen = 0;
        unordered_set<int>mp;

        for(auto it : nums) mp.insert(it);

        for(int i = 0 ; i<nums.size() ; i++)
        {
            int currlen = 1;
            int currnumber = nums[i];
            int nextnumber = currnumber + 1;
            while(mp.count(nextnumber)) 
            {
                currlen++;
                maxlen = max(maxlen , currlen);
                nextnumber++;
            }
        }

        return maxlen;
    }
};