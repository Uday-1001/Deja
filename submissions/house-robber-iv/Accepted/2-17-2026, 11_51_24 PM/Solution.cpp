// https://leetcode.com/problems/house-robber-iv

class Solution {
public:
    bool isPossible(vector<int>&nums,  int k , int mid)
    {
        int valid_houses = 0;
        for(int i = 0 ; i<nums.size() ; i++)
        {
            if(nums[i] <= mid)
            {
                i++;
                valid_houses++;
            } 
        }
    return valid_houses >= k;
    }

    int minCapability(vector<int>& nums, int k) {
        int s = *min_element(nums.begin() , nums.end());
        int e = *max_element(nums.begin() , nums.end());
        int ans = -1;

        while(s <= e)
        {
            int mid = s+ (e-s)/2;
            if(isPossible(nums , k , mid))
            {
                ans = mid;
                e = mid-1;
            }
            else s = mid+1;
        }
    return ans;
    }
};