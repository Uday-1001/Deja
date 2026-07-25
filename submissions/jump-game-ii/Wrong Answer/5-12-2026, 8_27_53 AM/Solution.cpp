// https://leetcode.com/problems/jump-game-ii

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return 1;

        int jumps = 0;
        int max_range = 0;
        int curr_range_end = 0;

        for(int i = 0 ; i<n ; i++)
        {
            max_range = max(max_range , i + nums[i]);
            if(i == curr_range_end)
            {
                jumps++;
                curr_range_end = max_range;
            }
            if(curr_range_end >= n-1) break;
        }
        return jumps;
    }
};