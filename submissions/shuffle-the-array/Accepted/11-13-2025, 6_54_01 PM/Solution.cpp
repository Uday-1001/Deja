// https://leetcode.com/problems/shuffle-the-array

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int>ans;
        int i = 0;
        int j = i + n;
        while(i < n and j < nums.size())
        {
            ans.push_back(nums[i]);
            i++;
            ans.push_back(nums[j]);
            j++;
        }
        return ans;

    }
};