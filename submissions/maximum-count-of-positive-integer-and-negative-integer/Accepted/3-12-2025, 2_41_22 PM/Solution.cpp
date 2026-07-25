// https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int neg_count = 0;
        int pos_count = 0;
        int i =0;

        while(i < nums.size())
        {
            if(nums[i] > 0)
               pos_count++; 
            
            if(nums[i] < 0)
                neg_count++;

            i++;
        }
        return max(pos_count , neg_count);
    }
};