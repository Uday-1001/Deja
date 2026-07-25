// https://leetcode.com/problems/find-peak-element

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        
        int s{} , e{n-1} , ans{-1};

        while(s <= e)
        {
            int mid = s + (e-s)/2;

            bool left = (mid == 0 or nums[mid] > nums[mid-1]);
            bool right = (mid == n-1 or nums[mid] > nums[mid+1]);

            if(left and right) 
            {
                ans = mid;
                e = mid - 1;
            }
            else if(mid > 0 and nums[mid] < nums[mid-1]) e = mid - 1;
            else s = mid + 1;
        }
        return ans;
    }
};