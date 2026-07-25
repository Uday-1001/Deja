// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii

class Solution {
public:
    int BinarySearch(vector<int>&nums)
    {
        int s = 0;
        int e = nums.size()-1;
        int ans = -1;

        while(s < e)
        {
            int mid = s + (e-s)/2;
            
            //measn right part is sorted after mid
            if(nums[mid] > nums[e]) s = mid + 1;
            else if(nums[mid] == nums[e]) e--;
            else if(nums[mid] < nums[e]) e = mid;
        }
        return nums[s];
    }

    int findMin(vector<int>& nums) {
        return BinarySearch(nums);
    }
};