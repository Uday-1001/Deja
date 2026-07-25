// https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold

class Solution {
public:
    bool ispossible(vector<int>& nums, int threshold, int mid)
    {
        int total_sum = 0;
        for(auto &x : nums)
        {
            total_sum += ceil((double)x / mid);
        }
        return total_sum <= threshold;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int s = 1;
        int e = *max_element(nums.begin() , nums.end());
        int ans = -1;

        while(s<=e)
        {
            int mid = s+(e-s)/2;
            if(ispossible(nums,threshold,mid))
            {
                ans = mid;
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
    return ans ;
    }
};