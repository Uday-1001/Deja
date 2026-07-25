// https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule

class Solution {
public:
    int byrec(vector<int>& jobDifficulty, int d , int index)
    {
        int n = jobDifficulty.size();
        if(d == 0) return 0;

        //ek case hum solve karenge
        int ans = INT_MAX;
        int maxdiff = INT_MIN;
        for(int i = index ; i <= n - d ; i++)
        {
            maxdiff = max(maxdiff , jobDifficulty[i]);
            int result = maxdiff + byrec(jobDifficulty , d-1 , i+1);
            ans = min(ans , result);
        }
        return ans;
    }

    int minDifficulty(vector<int>& jobDifficulty, int d) {
        if(jobDifficulty.size() < d) return -1;

        return byrec(jobDifficulty , d , 0);
    }
};