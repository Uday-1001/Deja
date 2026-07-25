// https://leetcode.com/problems/single-element-in-a-sorted-array

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int s{} , e{n-1};

        if(n == 1) return nums[0];

        while(s <= e)
        {
            int mid = s + (e-s) / 2;

            if(mid-1 >= 0 and mid+1 < n and nums[mid-1] != nums[mid] and nums[mid+1] != nums[mid]) return nums[mid];
            
            else if(mid-1 >= 0 and nums[mid-1] == nums[mid])
            {
                if(mid-1 >= 0 and (mid-1 & 1)) e = mid - 1;
                else s = mid + 1;
            }
            else if(mid+1 < n and nums[mid] == nums[mid+1])
            {
                if(mid+1 < n and ((mid+1) % 2 == 0)) e = mid - 1;
                else s = mid + 1;
            }
        }
        return -1;
    }
};