// https://leetcode.com/problems/rotate-function

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int firstsum = 0;
        int elemsum = 0;

        for(int i = 0 ; i<nums.size() ; i++)
        {
            firstsum += (i * nums[i]);
            elemsum += nums[i];
        }

        int maxsum = firstsum;

        for(int i = 1 ; i<nums.size() ; i++)
        {
            int newsum = firstsum + elemsum - (n * nums[n-i]);
            maxsum = max(maxsum , newsum);
            firstsum = newsum;
        }

        return maxsum;
    }
};