// https://leetcode.com/problems/maximum-amount-of-money-robot-can-earn

class Solution {
public:
    int byrec(vector<vector<int>>& coins , int i , int j , int k)
    {
        int n = coins.size();
        int m = coins[0].size();

        if(i == n-1 and j == m-1) 
        {
            if(coins[i][j] < 0 and k > 0) return max(0, coins[i][j]);
            else return coins[i][j];
        }

        //going right
        int right = INT_MIN;
        if(j+1 < m)
        {
            if(coins[i][j] < 0 and k > 0) 
            {
                int neutralize = 0 + byrec(coins , i , j+1 , k-1);
                int dont_neutralize = coins[i][j] + byrec(coins , i , j+1 , k);
                right = max(neutralize , dont_neutralize);
            }
            else right = coins[i][j] + byrec(coins , i , j+1 , k);
        }

        //going down
        int down = INT_MIN;
        if(i+1 < n)
        {
            if(coins[i][j] < 0 and k > 0) 
            {
                int neutralize = 0 + byrec(coins , i+1 , j , k-1);
                int dont_neutralize = coins[i][j] + byrec(coins , i+1 , j , k);
                down = max(neutralize , dont_neutralize);
            }
            else down = coins[i][j] + byrec(coins , i+1 , j , k);
        }

        return max(right , down);
    }

    int maximumAmount(vector<vector<int>>& coins) {
        return byrec(coins , 0 , 0 , 2);
    }
};