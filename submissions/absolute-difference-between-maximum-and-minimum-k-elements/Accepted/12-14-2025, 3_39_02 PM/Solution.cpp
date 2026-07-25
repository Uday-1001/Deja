// https://leetcode.com/problems/absolute-difference-between-maximum-and-minimum-k-elements

class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin() , nums.end());
        int temp =k;
        int sum = 0;
        while(k--)
        {
            sum += nums[n-1];
            n--;
        }
        int i = 0;
        while(temp--)
        {
            sum -= nums[i++];
        }  
        return abs(sum);
    }
};