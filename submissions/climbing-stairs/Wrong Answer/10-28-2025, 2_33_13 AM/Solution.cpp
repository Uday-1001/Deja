// https://leetcode.com/problems/climbing-stairs

class Solution {
public:
    int solve(int n)
    {
        if(n <= 0) return 0;

        int one_step = 0;
        int two_steps = 0;

        if(n >= 2)
        {
            two_steps = 2 + solve(n-2);
        }
        else if(n >= 1)
            one_step = 1 + solve(n-1);

        return one_step + two_steps;
    }

    int climbStairs(int n) {
        return solve(n);
    }
};