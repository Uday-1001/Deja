// https://leetcode.com/problems/find-peak-element

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        
        int s{} , e{n-1} , ans{-1};

        while(s <= e)
        {
            int mid = s + (e-s)/2;

            if((mid-1 >= 0 and mid+1 < n) and (nums[mid-1] < nums[mid] and nums[mid+1] < nums[mid]))  
            {
                ans = mid;
                e = mid - 1;
            }
            else s = mid + 1;
        }
        return ans;
    }
};