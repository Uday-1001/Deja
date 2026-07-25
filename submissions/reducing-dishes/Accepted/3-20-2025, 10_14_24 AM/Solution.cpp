// https://leetcode.com/problems/reducing-dishes

class Solution {
public:

    int byrec(vector<int>& satisfaction, int time, int i){
        // base case
        if(i >= satisfaction.size()){
            return 0;
        }
        // include
        int include = (satisfaction[i]*time) + byrec(satisfaction, time+1, i+1);
        // exclude
        int exclude = byrec(satisfaction, time, i+1);

        return max(include, exclude);
    }

    int bydp(vector<int>& satisfaction, int time, int i,vector<vector<int>> &dp){
        // base case
        if(i >= satisfaction.size()){
            return 0;
        }
        // already existing
        if(dp[time][i] != -1)
        {
            return dp[time][i];
        }
        // include
        int include = (satisfaction[i]*time) + bydp(satisfaction, time+1, i+1,dp);
        // exclude
        int exclude = bydp(satisfaction, time, i+1,dp);
        dp[time][i] = max(include, exclude);
        return dp[time][i];
    }

    int bytab(vector<int>& satisfaction){
        
        // create dp array
        int n = satisfaction.size();
        // analyse base case 
        // and fill dp array
        vector<vector<int>>dp(n+2, vector<int>(n+1,0));

        // top to bottom
        for(int time = n; time >= 1; time--){
            for(int i = n-1; i >= 0; i--){
                // include
                int include = (satisfaction[i]*time) + dp[time+1][i+1];
                // exclude
                int exclude = dp[time][i+1];
                dp[time][i] = max(include, exclude);
            }
        }
        return dp[0][n-1];
    }

    int byso(vector<int>& satisfaction){
        // create dp array
        int n = satisfaction.size();
        // analyse base case 
        // and fill dp array
        vector<int> curr (n+1, 0);
        vector<int> next (n+1, 0);
        // top to bottom
        for(int time = n; time >= 1; time--){
            for(int i = n-1; i >= 0; i--){
                // include
                int include = (satisfaction[i]*time) + next[i+1];
                // exclude
                int exclude = curr[i+1];
                curr[i] = max(include, exclude);
            }
            // shifting
            next = curr;
        }
        return curr[0];
    }

    int maxSatisfaction(vector<int>& satisfaction) {
        // int n = satisfaction.size();
        // vector<vector<int>>dp(n+1, vector<int>(n+1,-1));
        sort(satisfaction.begin(), satisfaction.end());
        // int ans = bydp(satisfaction, 1, 0,dp);
        int ans = byso(satisfaction);
        return ans;
    }
};