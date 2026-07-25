// https://leetcode.com/problems/maximum-alternating-subsequence-sum

class Solution {
public:
    long long byrec(vector<int>&nums , bool flag , int i)
    {
        if(i >= nums.size()) return 0;
        
        //ek case hum solve karenge
        long long even_sum = 0;
        long long odd_sum = 0;
        long long include = 0;
        if(flag == true)
        {
            even_sum = nums[i] + byrec(nums , !flag , i+1);
            include = max(include , even_sum);
        }
        else
        {
            odd_sum = -nums[i] + byrec(nums , !flag , i+1);
            include = max(include , odd_sum);
        }
        long long exclude = 0 + byrec(nums , flag , i+1);

        return max(include , exclude);
    }   

    long long maxAlternatingSum(vector<int>& nums) {    
        return byrec(nums , true , 0);
    }
};