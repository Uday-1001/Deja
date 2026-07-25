// https://leetcode.com/problems/divide-an-array-into-subarrays-with-minimum-cost-i

class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int cost = nums[0];

        int firstmini = INT_MAX;
        int secondmini = INT_MAX;

        for(int i = 1 ; i<nums.size() ; i++)
        {
            if(nums[i] < firstmini)
            {
                secondmini = firstmini;
                firstmini = nums[i];
            }
            else 
            {
                secondmini = min(secondmini ,nums[i]);
            }
        }
        return cost + firstmini + secondmini;
    }
};