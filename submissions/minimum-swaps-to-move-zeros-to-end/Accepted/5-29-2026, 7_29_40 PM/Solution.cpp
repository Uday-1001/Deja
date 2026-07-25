// https://leetcode.com/problems/minimum-swaps-to-move-zeros-to-end

class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int zeros = 0;
        for(auto it : nums) if(it == 0) zeros++;

        int steps = 0;
        for(int i = nums.size()-1 ; i>=0 ; i--)
        {
            if(zeros == 0) break;
            if(nums[i] != 0) 
            {
                steps++;
            }
            zeros--;
        }
        return steps;
    }
};