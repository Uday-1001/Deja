// https://leetcode.com/problems/limit-occurrences-in-sorted-array

class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        vector<int>ans;
        ans.push_back(nums[0]);

        int count = 1;
        for(int i = 1 ; i<nums.size() ; i++)
        {
            if(nums[i] == nums[i-1])
            {
                count++;
                if(count <= k) ans.push_back(nums[i]);
            }
            else
            {
                count = 1;
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};