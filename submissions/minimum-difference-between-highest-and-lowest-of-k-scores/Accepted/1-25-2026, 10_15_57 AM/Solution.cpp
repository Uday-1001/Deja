// https://leetcode.com/problems/minimum-difference-between-highest-and-lowest-of-k-scores

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin() , nums.end());

        if(n == 1) return 0;

        int min_diff = INT_MAX;
        for(int i = 0 ; i+(k-1)<n ; i++)
        {
            int lowest = nums[i];
            int highest = nums[i+(k-1)];
            int diff = abs(highest - lowest);
            min_diff = min(min_diff , diff);
        }
    return min_diff;
    }
};