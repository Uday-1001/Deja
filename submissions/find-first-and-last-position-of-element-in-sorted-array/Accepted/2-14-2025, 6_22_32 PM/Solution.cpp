// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array

class Solution {
public:
    int FirstOccurence(vector<int>& nums, int target, int &first)
    {
        int s =0 , e = nums.size()-1;
        
        while(s<=e)
        {
            int mid = s+(e-s)/2;
            if(nums[mid] == target) 
            {
                first = mid;
                e = mid - 1;
            }
            if(nums[mid] > target)
            e = mid - 1;
            if(nums[mid] < target)
            s = mid + 1;
        }
    return first;
    }
     
    int LastOccurence(vector<int>& nums, int target , int &last)
    {
        int s =0 , e = nums.size()-1;
        
        while(s<=e)
        {
            int mid = s+(e-s)/2;
            if(nums[mid] == target)
            {
                last = mid;
                s = mid + 1;
            } 
            
            if(nums[mid] > target)
            e = mid - 1;
            if(nums[mid] < target)
            s = mid + 1;
        }
    return last;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans(2);

        int first = -1 , last = -1 ;

        int first_occ = FirstOccurence(nums, target ,first);
        int last_occ = LastOccurence(nums, target , last);

        ans[0] = first_occ;
        ans[1] = last_occ;

        return ans ;
    }
};