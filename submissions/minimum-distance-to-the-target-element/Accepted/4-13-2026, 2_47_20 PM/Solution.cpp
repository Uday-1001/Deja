// https://leetcode.com/problems/minimum-distance-to-the-target-element

class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int ans_forward = INT_MAX;
        int ans_backward = INT_MAX;

        for(int i = 0 ; i<nums.size() ; i++) if(nums[i] == target) ans_forward = min(ans_forward , abs(i - start));
        for(int i = nums.size()-1 ; i>=0 ; i--) if(nums[i] == target) ans_backward = min(ans_backward , abs(i - start));
        
        return min(ans_forward , ans_backward);
    }
};