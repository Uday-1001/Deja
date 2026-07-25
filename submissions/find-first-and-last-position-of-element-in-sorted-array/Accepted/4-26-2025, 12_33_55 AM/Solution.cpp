// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array

class Solution {
public:
    int First_occurence(vector<int>&nums , int target)
    {
        int s = 0;
        int e = nums.size()-1;
        int first_occ = -1;
        
        while(s<=e)
        {
            int mid = s+(e-s)/2;
            if(nums[mid] == target)
            {
                first_occ = mid;
                e = mid - 1;
            }
            else if(nums[mid] > target)
            {
                e = mid - 1;
            }
            else
                s = mid + 1;
        }
        return first_occ;
    }

    int Last_occurence(vector<int>&nums , int target)
    {
        int s = 0;
        int e = nums.size()-1;
        int last_occ = -1;
        
        while(s<=e)
        {
            int mid = s+(e-s)/2;
            if(nums[mid] == target)
            {
                last_occ = mid;
                s = mid + 1;
            }
            else if(nums[mid] > target)
            {
                e = mid - 1;
            }
            else
                s = mid + 1;
        }
        return last_occ;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = First_occurence(nums , target);
        int last = Last_occurence(nums , target);

        return{first , last};
    }
};