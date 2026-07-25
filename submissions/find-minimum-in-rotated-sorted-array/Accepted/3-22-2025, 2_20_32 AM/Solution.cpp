// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int s = 0;
        int e = n-1;
        int ans = INT_MAX;

        while(s<=e)
        {
            int mid  = s+(e-s)/2;

            if(nums[s] <= nums[mid])
            {
                //means left half of the array is sorted
                int left_most = nums[s];
                //taking leftmost as it is the smallest in hte sorted part of the array
                ans = min(ans , left_most);
                s = mid +1;
            }
            else if(nums[mid] <= nums[e])
            {
                //means right part is sorted
                int left_most = nums[mid];
                ans = min(ans , left_most);
                e = mid -1;
            }
        }
    return ans;
    }
};