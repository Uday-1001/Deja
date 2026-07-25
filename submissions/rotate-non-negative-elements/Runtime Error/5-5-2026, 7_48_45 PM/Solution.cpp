// https://leetcode.com/problems/rotate-non-negative-elements

class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int>positives;
        for(auto it : nums) if(it > 0) positives.push_back(it);

        int m = positives.size();
        k %= m;
        rotate(positives.begin() , positives.begin() + k , positives.end());

        int index = 0;
        for(int i = 0 ; i<n ; i++)
        {
            if(nums[i] > 0) nums[i] = positives[index++];
        }
        return nums;
    }
};