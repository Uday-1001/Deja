// https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits

class Solution {
public:
    int sum_digits(int num)
    {
        int sum = 0;
        while(num > 0)
        {
            int digits = num % 10;
            sum += digits;
            num = num / 10;
        }
    return sum;

    }
    int maximumSum(vector<int>& nums) {
        int sum = 0;
        int max_sum = -1;
        
        for(int i = 0 ; i<nums.size() ; i++)
        {
            for(int j = i+1 ; j<nums.size() ;j++)
            {
                int first_num = nums[i];
                int second_num = nums[j];

                int s1 = sum_digits(first_num);
                int s2 = sum_digits(second_num);

                if(s1 == s2)
                {
                    max_sum = max(max_sum ,(first_num + second_num));
                }
            }
        }
    return max_sum;
    }
};