// https://leetcode.com/problems/compare-sums-of-bitonic-parts

class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        int n = nums.size();
        int peak = -1;
        int sum_left = 0;
        int sum_right = 0;

        for(int i = 0 ; i<n ; i++)
        {
            if(i-1 >= 0 and i+1 < n and (nums[i] > nums[i-1] and nums[i] > nums[i+1]))
            {
                peak = i;
                break;
            }
        }
        
        for(int i = 0 ; i<=peak ; i++) sum_left += nums[i];
        for(int i = peak ; i<n ; i++) sum_right += nums[i];

        if(sum_left > sum_right) return 0;
        if(sum_right > sum_left) return 1;
        return -1;
    }
};