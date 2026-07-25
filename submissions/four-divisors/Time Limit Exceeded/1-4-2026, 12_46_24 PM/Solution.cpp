// https://leetcode.com/problems/four-divisors

class Solution {
public:
    pair<int,int> countingthem(int n)
    {
        int count = 1;
        int sum = 1;

        for(int i = 2 ; i <= n ; i++)
        {
            if(n % i == 0) 
            {
                count++;
                sum += i;
            }
        }
    return {count , sum};
    }

    int sumFourDivisors(vector<int>& nums) {
        int total = 0;
        for(int i = 0; i < nums.size() ; i++)
        {
            auto [getcount , sum] = countingthem(nums[i]);
            if(getcount < 4 or getcount > 4) continue;
            else 
            {
                total += sum;
            }
        }
    return total;
    }
};