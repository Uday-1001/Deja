// https://leetcode.com/problems/search-in-rotated-sorted-array

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int s= 0 ;
        int e = nums.size()-1;

        while(s<=e)
        {
            int mid = s+(e-s)/2;
            if(target == nums[mid])
            {
                return mid;
            }
            //check which part is sorted ? right  or the left part
            if(nums[mid]<=nums[e])
            {
                //means right part is sorted 
                if(target <= nums[e] && target >= nums[mid])
                {
                    s = mid + 1;
                }
                else
                    e = mid - 1;
            }
            else
            {
                // left part is sorted
                if(target <= nums[mid] && target >= nums[s])
                {
                    e = mid - 1;
                }
                else
                    s = mid + 1;
            }
        }
        return -1;
    }
};