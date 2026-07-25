// https://leetcode.com/problems/array-with-elements-not-equal-to-average-of-neighbors

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        vector<int>ans(nums.size());

        int left = 0 ;
        int right = nums.size()-1;

        int  i= 0;
        while(left < right)
        {
            ans[i] = nums[left];
            ans[i+1] = nums[right];
            left++;
            right --;
            i += 2;
        }
        if(nums.size() & 1)
        {
            ans[i] = nums[left];
        }
        return ans;
    }
};