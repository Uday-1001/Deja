// https://leetcode.com/problems/solving-questions-with-brainpower

class Solution {
public:
    long long bydp(vector<vector<int>>& questions , int index , vector<long long>&dp)
    {
        //base case
        if(index >= questions.size()) return 0;
        //check existence for value
        if(dp[index] != -1)
        {
            return dp[index];
        }

        int points = questions[index][0];
        int brain = questions[index][1];

        //include -> question ko solve kiya to kya hua 
        long long solved = points + bydp(questions , index + brain + 1 ,dp);
        //exclude -> question ko solve he nhi kiya to kya hua
        long long unsolved = bydp(questions , index + 1 ,dp);
        //returning the max of the both possibilities
        dp[index]= max(solved , unsolved);
        return dp[index];
    }
    
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long>dp(n+1 , -1);
        return bydp(questions , 0 , dp);

    }
};