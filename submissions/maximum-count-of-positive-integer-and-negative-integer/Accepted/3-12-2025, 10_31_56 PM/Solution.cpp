// https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer

class Solution {
public:

    int BinarySearch(vector<int> nums ,int s ,int e , int target)
    {
        while(s<=e)
        {
            int mid = s+(e-s)/2;

            if(nums[mid] <= target) 
                s = mid + 1 ;
            else 
                e = mid - 1;
        }
        return s;
    }

    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int s = 0 ,  e = n-1 ;

        int negative_position = BinarySearch(nums , s , e , -1);
        int positive_position = BinarySearch(nums , negative_position , e , 0);
        int pos_count = n - positive_position;

        return max(negative_position , pos_count);
    }
};