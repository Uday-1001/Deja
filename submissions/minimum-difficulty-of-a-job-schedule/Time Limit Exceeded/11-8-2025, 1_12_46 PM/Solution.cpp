// https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule

class Solution {
public:
    int byrec(vector<int>& jobDifficulty, int d , int index)
    {
        int n = jobDifficulty.size();
        if(d == 0 and index == n) return 0;
        if(d == 0 or index == n) return 1e9;

        //ek case hum solve karenge
        int ans = INT_MAX;
        int maxdiff = 0;
        for(int i = index ; i < n ; i++)
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