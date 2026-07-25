// https://leetcode.com/problems/sum-of-good-numbers

class Solution {
public:
    int sumOfGoodNumbers(vector<int>& nums, int k) {
        int sum =0;
        for(int i=0 ; i<nums.size() ; i++){
            bool good = true;
            if(i-k >= 0 and (nums[i] <= nums[i-k])) good = false;
            if(i+k < nums.size() and (nums[i] <= nums[i+k])) good = false;

            if(good) sum += nums[i];
        }
        return sum;
    }
};