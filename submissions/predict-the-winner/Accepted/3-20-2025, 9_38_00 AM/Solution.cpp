// https://leetcode.com/problems/predict-the-winner

class Solution {
public:
    int bydp(vector<int>& nums , int i , int j , vector<vector<int>>&dp)
    {
        //base case
        if(i>j) return 0;
        //single score
        if(i==j) return nums[i];
        if(dp[i][j] != -1)
        {
            return dp[i][j];
        }
        
        int taking_i = nums[i] + min(bydp(nums,i+2,j,dp) , bydp(nums,i+1,j-1,dp));
        
        int taking_j = nums[j] + min(bydp(nums,i+1,j-1,dp) , bydp(nums,i,j-2,dp));

        dp[i][j] = max(taking_i , taking_j);

        return dp[i][j];
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        int total_score = accumulate(nums.begin(), nums.end() , 0);
        vector<vector<int>>dp(n+1 , vector<int>(n+1,-1));
        int player1 = bydp(nums , 0 , n-1 , dp);
        int player2 = total_score - player1;
        return player1 >= player2;
    }
};