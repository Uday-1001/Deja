// https://leetcode.com/problems/russian-doll-envelopes

class Solution {
public:
    bool isValidToPlace(vector<int>prev , vector<int>curr)
    {
        return (prev[0] < curr[0] && prev[1] < curr[1]);
    }

    int bytab(vector<vector<int>>& envelopes)
    {
        int n = envelopes.size();
        vector<vector<int>>dp(n+1 , vector<int>(n+1 , 0));

        for(int curr = n-1 ; curr>=0 ; curr--)
        {
            for(int prev = curr-1 ; prev>=-1 ; prev--)
            {
                int include = 0;
                if(prev == -1 || isValidToPlace(envelopes[prev] , envelopes[curr]))
                {
                    include = 1 + dp[curr+1][curr+1];
                }
                int exclude = 0 + dp[prev+1][curr+1];

                dp[prev+1][curr] = max(include , exclude);
            }
        }
    return dp[0][0];
    }

    // int bymemo(vector<vector<int>>& envelopes , int prev , int curr , vector<vector<int>>& dp)
    // {
    //     if(curr >= envelopes.size()) return 0;
    //     if(dp[prev+1][curr] != -1) return dp[prev+1][curr];

    //     //ek case hum log check karenge aur solve krdenge 
    //     int include = 0;
    //     if(prev == -1 || isValidToPlace(envelopes[prev] , envelopes[curr]))
    //     {
    //         include = 1 + bymemo(envelopes , curr , curr+1 , dp);
    //     }
    //     int exclude = 0 + bymemo(envelopes , prev , curr+1 , dp);

    //     return dp[prev+1][curr] = max(include , exclude);
    // }

    // int byrec(vector<vector<int>>& envelopes , int prev , int curr)
    // {
    //     if(curr >= envelopes.size()) return 0;

    //     //ek case hum log check karenge aur solve krdenge 
    //     int include = 0;
    //     if(prev == -1 || isValidToPlace(envelopes[prev] , envelopes[curr]))
    //     {
    //         include = 1 + byrec(envelopes , curr , curr+1);
    //     }
    //     int exclude = 0 + byrec(envelopes , prev , curr+1);

    //     return max(include , exclude);
    // }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        sort(envelopes.begin() , envelopes.end());

        // return byrec(envelopes , -1 , 0);    

        // vector<vector<int>>dp(n+1 , vector<int>(n+1 , -1));
        // return bymemo(envelopes , -1 , 0 , dp);

        return bytab(envelopes);

    }
};