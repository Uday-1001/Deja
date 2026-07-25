// https://leetcode.com/problems/single-element-in-a-sorted-array

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int s = 0;
        int e = nums.size()-1;
        
        while(s<=e)
        {
            if(s == e) return nums[s];

            int mid = s+(e-s)/2;
            if((mid-1 >=0 && nums[mid] != nums[mid-1]) &&(mid+1 < nums.size() && nums[mid] != nums[mid+1]))
            {
                return nums[mid];
            }
            if(mid-1 >=0 && nums[mid] == nums[mid-1])
            {
                int index = mid-1;
                if(index & 1)
                {
                    e = mid-1;
                }
                else
                    s = mid+1;
            }
            else if(mid+1 < nums.size() && nums[mid] == nums[mid+1])
            {
                int index = mid;
                if(index & 1)
                {
                    e = mid-1;
                }
                else
                    s = mid+1;
            }
        }
    return -1;
    }
};