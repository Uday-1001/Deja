// https://leetcode.com/problems/burst-balloons

class Solution {
public:
    int byrec(vector<int>&nums)
    {
        //base case
        if(nums.size() == 1) return nums[0];

        //hum saari possibilities explore karenge
        int maxi = INT_MIN;
        for(int i=0 ; i<nums.size() ; i++)
        {
            int val = nums[i];
            int prev_val = i-1 < 0 ? 1 : nums[i-1];
            int next_val = i+1 >=nums.size() ? 1 : nums[i+1];

            int coins_gained = prev_val * val * next_val;

            //remove the element
            int removed = nums[i];
            nums.erase(nums.begin() + i);

            int total = coins_gained + byrec(nums);
            maxi = max(maxi , total);
            //re inserting the element
            nums.insert(nums.begin() + i , removed);
        }
        return maxi;
    }

    int maxCoins(vector<int>& nums) {
        return byrec(nums);
    }
};