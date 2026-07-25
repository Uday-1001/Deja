// https://leetcode.com/problems/apply-operations-to-an-array

class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<nums.size() ; i++)
        {
            if(nums[i] > 0)
            {
            if(i+1 < nums.size() && nums[i] == nums[i+1])
            {
                nums[i] = nums[i] * 2;
                nums[i+1] = 0;
            }
            }
        }
        int count = 0;
     
    for (int i = 0; i < nums.size(); i++) 
    {
        if (nums[i] != 0) 
        {
            swap(nums[i], nums[count]);
            count++;
        }
    }
    return nums;
    }
};