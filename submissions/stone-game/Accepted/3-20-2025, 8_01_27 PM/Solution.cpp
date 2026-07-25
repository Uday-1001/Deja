// https://leetcode.com/problems/stone-game

class Solution {
public:
    //By Recursion
    int solve(vector<int>& piles , int i , int j)
    {
        //base case
        if(i>j) return 0;
        //single score
        if(i==j) return piles[i];
        
        int taking_i = piles[i] + min(solve(piles,i+2,j) , solve(piles,i+1,j-1));
        
        int taking_j = piles[j] + min(solve(piles,i+1,j-1) , solve(piles,i,j-2));

        return max(taking_i , taking_j);
    }

    // By Memoization in DP
    int bydp(vector<int>& piles , int i , int j,vector<vector<int>>&dp)
    {
        //base case
        if(i>j) return 0;
        //single score
        if(i==j) return piles[i];

        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        
        int taking_i = piles[i] + min(bydp(piles,i+2,j,dp) , bydp(piles,i+1,j-1,dp));
        
        int taking_j = piles[j] + min(bydp(piles,i+1,j-1,dp) , bydp(piles,i,j-2,dp));

        dp[i][j] = max(taking_i , taking_j);
        
        return dp[i][j];
    }

    // By Tabulation in DP
    int bytab(vector<int>&piles)
    {
        int n = piles.size();
        //create dp array
        vector<vector<int>>dp(n+2 , vector<int>(n+2,0));

        //analyse base case
        for(int row = n-2 ; row>=1 ; row--)
        {
            for(int col = n-1 ; col>=0 ; col--)
            {
                int taking_i = piles[row] + min(dp[row+2][col] , dp[row+1][col-1]);
                int taking_j = piles[col] + min(dp[row+1][col-1] , dp[row][col-2]); 

                dp[row][col] = max(taking_i , taking_j);
            }
        }
    return dp[0][0];
    }

    bool stoneGame(vector<int>& piles) {
        int n= piles.size();
        int total_score = accumulate(piles.begin() , piles.end() , 0);
        vector<vector<int>>dp(n+1 , vector<int>(n+1,-1));
        int alice = bydp(piles,0 , n-1 , dp);
        int bob = total_score - alice;
        return alice >= bob;
    }
};