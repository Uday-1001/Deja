// https://leetcode.com/problems/find-all-possible-stable-binary-arrays-i

class Solution {
public:
    int mod = 1e9 + 7;
    vector<vector<vector<int>>>dp;

    int byrec(int zeros , int ones , bool previsOne , int limit)
    {
        if(zeros == 0 and ones == 0) return 1;
        if(dp[zeros][ones][previsOne] != -1) return dp[zeros][ones][previsOne];

        long long ans = 0;
        if(previsOne)
        {
            //if previous was one , then we will explore zero based path
            for(int count = 1 ; count <= min(limit , zeros) ; count++)
            {
                ans += byrec((zeros - count), ones , false , limit);
            }
        }
        else
        {
            //if previous was zero , then we will explore one based path
            for(int count = 1 ; count <= min(limit , ones) ; count++)
            {
                ans += byrec(zeros , (ones - count) , true , limit);
            }
        }

        return dp[zeros][ones][previsOne] = ans % mod;
    }

    int numberOfStableArrays(int zero, int one, int limit) {
        dp.resize(zero+1 , vector<vector<int>>(one+1 , vector<int>(2 , -1)));

        int startones = byrec(zero , one , false , limit);
        int startzeros = byrec(zero , one , true , limit);

        return (startones + startzeros) % mod;
    }
};