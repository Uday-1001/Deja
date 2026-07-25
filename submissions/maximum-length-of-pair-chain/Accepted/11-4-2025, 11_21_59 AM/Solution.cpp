// https://leetcode.com/problems/maximum-length-of-pair-chain

class Solution {
public:

    int bytab(vector<vector<int>>&pairs)
    {
        int n = pairs.size();
        vector<vector<int>>dp(n+1 , vector<int>(n+1 ,0));
        
        for(int curr = n-1 ; curr >= 0 ; curr--)
        {
            for(int prev = curr-1 ; prev >= -1 ; prev--)
            {
                int include = 0;
                if(prev == -1 or pairs[prev][1] < pairs[curr][0])
                {
                    include = 1 + dp[curr+1][curr+1];
                }
                int exclude = 0 + dp[prev+1][curr+1];

                dp[prev+1][curr] = max(include , exclude);
            }
        }
    return dp[0][0];
    }

    // int bymemo(vector<vector<int>>&pairs , int prev , int curr , vector<vector<int>>&dp)
    // {
    //     if(curr >= pairs.size()) return 0;
    //     if(dp[prev+1][curr] != -1) return dp[prev+1][curr];

    //     int include = 0;
    //     if(prev == -1 or pairs[prev][1] < pairs[curr][0])
    //     {
    //         include = 1 + bymemo(pairs , curr , curr+1 , dp);
    //     }
    //     int exclude = 0 + bymemo(pairs , prev , curr+1 , dp);

    //     return dp[prev+1][curr] = max(include , exclude);
    // }

    // int byrec(vector<vector<int>>&pairs , int prev , int curr)
    // {
    //     //base case
    //     if(curr >= pairs.size()) return 0;

    //     //ek case hum solve karenge 
    //     int include = 0;
    //     if(prev == -1 or pairs[prev][1] < pairs[curr][0])
    //     {
    //         include = 1 + byrec(pairs , curr , curr+1);
    //     }
    //     int exclude = 0 + byrec(pairs , prev , curr+1);

    //     return max(include , exclude);
    // }

    int findLongestChain(vector<vector<int>>& pairs) {
        sort(begin(pairs), end(pairs));
        // return byrec(pairs ,-1 , 0);

        // int n = pairs.size();
        // vector<vector<int>>dp(n+1 , vector<int>(n+1 , -1));
        // return bymemo(pairs, -1 , 0 , dp);

        return bytab(pairs);

    }
};