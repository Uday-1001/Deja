// https://leetcode.com/problems/max-consecutive-ones

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int max_cnt = 0;
        for(auto num : nums)
        {
            if(num == 1)
            {
                count++;
                max_cnt = max(max_cnt , count);
            }
            else
                count = 0;   
        }
        return max_cnt;
    }
};