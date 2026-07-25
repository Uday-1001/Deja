// https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold

class Solution {
public:
    bool ispossible(vector<int>& nums, int threshold , int mid)
    {
        int total = 0;
        for(int i=0 ; i<nums.size() ; i++)
        {
            total += ceil((double)nums[i] / mid);
        }
        return (total <= threshold);
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int s = 1;
        int e = *max_element(begin(nums) , end(nums));
        int ans = -1;

        while(s <= e)
        {
            int mid = s +(e-s)/2;
            if(ispossible(nums , threshold , mid))
            {
                ans = mid;
                e = mid -1;
            }
            else
            {
                s = mid +1;
            }
        }
    return ans;
    }
};