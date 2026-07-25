// https://leetcode.com/problems/longest-consecutive-sequence

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int maxlen = 0;
        unordered_set<int>st(begin(nums) , end(nums));

        for(int i = 0 ; i<nums.size() ; i++)
        {
            int currlen = 1;
            int currnumber = nums[i];

            if(!st.count(currnumber - 1))
            {
                while(st.count(currnumber + 1))
                {
                    currlen++;
                    currnumber++;
                }
                maxlen = max(maxlen , currlen);
            }
        }

        return maxlen;
    }
};