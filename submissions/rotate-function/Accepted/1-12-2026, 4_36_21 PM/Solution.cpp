// https://leetcode.com/problems/rotate-function

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN;
        int first = 0 , sum = 0;

        for(int i =0 ; i<n ; i++)
        {
            first += i * nums[i];
            sum += nums[i];
        }
        int max_sum = first;

        for(int i = 1 ; i<n ; i++)
        {
            int new_sum = (first + sum) - (n * nums[n-i]);
            max_sum = max(max_sum , new_sum);
            first = new_sum; 
        }
    return max_sum;
    }
};