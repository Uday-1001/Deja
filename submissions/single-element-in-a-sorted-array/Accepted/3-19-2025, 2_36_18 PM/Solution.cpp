// https://leetcode.com/problems/single-element-in-a-sorted-array

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int s = 0;
        int e = nums.size()-1;
        int mid = s+(e-s)/2;

        while(s<=e)
        {
            int rightval =-1;
            if(mid+1 < nums.size())
            {
                rightval = nums[mid+1];
            }
            int leftval = -1;
            if(mid-1 >= 0)
            {
                leftval = nums[mid-1];
            }
            int curr = nums[mid];

            if(s == e) return nums[s];

            if(curr != leftval && curr != rightval)
            {
                return nums[mid];
            }
            if(curr == leftval && curr != rightval)
            {
                int index = mid-1;
                if(index & 1)
                {
                    e = mid-1;
                }
                else
                    s = mid+1;
            }
            else if(curr != leftval && curr == rightval)
            {
                int index = mid;
                if(index & 1)
                {
                    e = mid-1;
                }
                else
                    s = mid+1;
            }
            mid = s + (e-s)/2;
        }
    return -1;
    }
};