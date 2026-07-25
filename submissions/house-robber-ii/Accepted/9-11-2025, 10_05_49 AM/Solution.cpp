// https://leetcode.com/problems/house-robber-ii

class Solution {
public:
    int dp[1001][1001];

    int solve (vector<int>& nums ,int start, int end)
    {
        //base case 
        if(start > end) return 0;

        if(dp[start][end] != -1) return dp[start][end];

        //ek case hum solve karenge baaki ka recursion chacha dekh lenge

        //include the house
        int includeAns = nums[start] + solve(nums , start+2 , end);

        //exclude the house 
        int excludeAns = 0 + solve(nums , start+1 , end);
        
        //return the max value of the two
        int final = max(includeAns , excludeAns);
        return dp[start][end] = final;
    }

    int rob(vector<int>& nums) {
        memset(dp , -1 , sizeof(dp));

        int n = nums.size();
        //single element case 

        if(n == 1) return nums[0];

        int option_1 = solve(nums , 0 , n-2);

        int option_2 = solve(nums , 1 , n-1);

        int ans = max(option_1 , option_2);
        return ans;
    }
};