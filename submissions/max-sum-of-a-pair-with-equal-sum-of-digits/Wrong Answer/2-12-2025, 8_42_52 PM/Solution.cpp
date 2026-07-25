// https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits

class Solution {
public:
    int sumOfDigits(int num)
    {
        int sum= 0;
        while(num>0)
        {
            sum += (num % 10);
            num /= 10;
        }
    return sum;
    }

    int maximumSum(vector<int>& nums) {
        int max_sum = -1;
        unordered_map<int,int>mapping;

        for(int i =0; i<nums.size() ;i++)
        {
            int digit_sum = sumOfDigits(nums[i]);

            if(mapping.find(digit_sum) != mapping.end())
            {
                max_sum = max(max_sum , nums[i] + mapping[digit_sum]);
            }
            mapping[digit_sum] = nums[i];
        }
    return max_sum;
    }
};