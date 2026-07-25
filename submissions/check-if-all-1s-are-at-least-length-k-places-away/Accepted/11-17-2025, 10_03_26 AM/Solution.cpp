// https://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int last_seen = -1;
        for(int i=0 ; i<nums.size() ; i++)
        {
            if(nums[i] == 1)
            {
                if(last_seen != -1 and i- last_seen -1 < k) return false;
                last_seen = i;
            }
        }
    return true;
    }
};