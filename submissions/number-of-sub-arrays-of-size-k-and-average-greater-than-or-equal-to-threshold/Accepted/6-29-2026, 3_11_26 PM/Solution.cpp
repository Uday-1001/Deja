// https://leetcode.com/problems/number-of-sub-arrays-of-size-k-and-average-greater-than-or-equal-to-threshold

class Solution {
public:
    int SlidingWindow(vector<int>&nums , int k , int threshold)
    {   
        int count = 0;
        int sum = 0;

        for(int i = 0 ; i<k ; i++) sum += nums[i];
        if((sum / k) >= threshold) count++;

        for(int i = k ; i<nums.size() ; i++)
        {
            sum += nums[i];
            sum -= nums[i - k];
            if((sum / k) >= threshold) count++;
        }
        
        return count;
    }

    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        return SlidingWindow(arr , k , threshold);
    }
};