// https://leetcode.com/problems/longest-consecutive-sequence

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int maxlen = 0;
        unordered_set<int>st(begin(nums) , end(nums));

        for(auto it : st)
        {
            int currlen = 1;
            int currnumber = it;

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