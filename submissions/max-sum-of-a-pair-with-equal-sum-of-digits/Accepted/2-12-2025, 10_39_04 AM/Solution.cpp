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
    
        int max_sum = -1;

        unordered_map<int,int> mp;

        for(auto num : nums)
        {
            int digit_sum = sum_digits(num) ;
            if(mp.find(digit_sum) != mp.end())
            {
                max_sum = max(max_sum , (num + mp[digit_sum]));
            }
            mp[digit_sum] = max(mp[digit_sum],num);
        }
    return max_sum;    
    }
};