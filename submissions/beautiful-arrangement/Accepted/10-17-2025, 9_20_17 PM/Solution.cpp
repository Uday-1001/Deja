// https://leetcode.com/problems/beautiful-arrangement

class Solution {
public:
    int count = 0;

    void solve(int n , vector<bool>&used_nums , int i)
    {
        //base case 
        if(i > n)
        {
            count++;
            return;
        }
        //ek case hum solve karenge baaki recursion dekhlega
        for(int num = 1 ; num <= n ; num++)
        {
            if(!used_nums[num] && (num % i ==0 || i % num ==0))
            {
                used_nums[num] = true;
                solve(n , used_nums , i+1);

                used_nums[num] = false;
            }
        }
    }

    int countArrangement(int n) {
        vector<bool>used_nums(n+1 , false);
        int i = 1;

        solve(n , used_nums , i);
        return count;
    }
};