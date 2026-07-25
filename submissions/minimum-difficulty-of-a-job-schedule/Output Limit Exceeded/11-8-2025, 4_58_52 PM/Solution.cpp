// https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule

class Solution {
public:
    // int bymemo(vector<int>& jobDifficulty, int d , int index , vector<vector<int>>&dp)
    // {
    //     int n = jobDifficulty.size();
    //     if(d == 0 and index == n) return 0;
    //     if(d == 0 or index == n) return 1e9;
    //     if(dp[d][index] != -1) return dp[d][index];

    //     //ek case hum solve karenge
    //     int ans = INT_MAX;
    //     int maxdiff = 0;
    //     for(int i = index ; i < n ; i++)
    //     {
    //         maxdiff = max(maxdiff , jobDifficulty[i]);
    //         int result = maxdiff + bymemo(jobDifficulty , d-1 , i+1 , dp);
    //         ans = min(ans , result);
    //     }
    //     return dp[d][index] = ans;
    // }

    int byrec(vector<int>& jobDifficulty, int d , int index)
    {
        int n = jobDifficulty.size();
        if(d == 0 and index == n) 
        {
            cout<<"returning 0"<<endl;
            return 0;
        }
        if(d == 0 or index == n) 
        {
            cout<<"returning 1e8"<<endl;
            return 1e8;
        }

        //ek case hum solve karenge
        int ans = INT_MAX;
        int maxdiff = 0;
        for(int i = index ; i < n ; i++)
        {
            maxdiff = max(maxdiff , jobDifficulty[i]);
            cout<<"Maxdiff = ";
            cout<<maxdiff<<endl;
            int result = maxdiff + byrec(jobDifficulty , d-1 , i+1);
            cout<<"Updating answer now as ";
            ans = min(ans , result);
            cout<<ans<<endl;
        }
        return ans;
    }

    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if(jobDifficulty.size() < d) return -1;

        return byrec(jobDifficulty , d , 0);
        

        // vector<vector<int>>dp(d+1 , vector<int>(n+1 , -1));
        // return bymemo(jobDifficulty , d , 0 , dp);
    }
};