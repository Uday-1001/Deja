// https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag

class Solution {
public:
    bool IsPossible(vector<int>& nums , int mid, int maxOps)
    {
       int n = nums.size();
       for(auto it : nums)
       {
            int remain = it / mid;
            if(it % mid == 0)
            {
                maxOps = maxOps - (remain -1);
            }
            else
            {
                maxOps = maxOps - remain;
            }
            if(maxOps < 0)  return false;
       }
    return true;
    }
    int minimumSize(vector<int>& nums, int maxOps) {
        int s = 1;
        int e = *max_element(nums.begin() , nums.end());
        int ans = e;

        while(s<=e)
        {
            int mid = s+(e-s)/2;
            if(IsPossible( nums,mid,maxOps ))
            {
                ans =mid;
                e = mid -1;
            }
            else
            {
                s = mid +1;
            }
        }
    return ans ;
    }
};