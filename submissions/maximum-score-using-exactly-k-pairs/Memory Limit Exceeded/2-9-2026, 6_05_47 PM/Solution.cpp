// https://leetcode.com/problems/maximum-score-using-exactly-k-pairs

class Solution {
public:
    using ll = long long;

    // ll byspaceop(int copyn, int copym , int copyk , vector<int>& nums1, vector<int>& nums2)
    // {
    //     vector<vector<ll>>curr(copym+1 , vector<ll>(copyk+1 , -1e18));
    //     vector<vector<ll>>next(copym+1 , vector<ll>(copyk+1 , -1e18));

    //     for(int j = 0 ; j<=copym ; j++)
    //     {
    //         curr[j][0] = 0;
    //         next[j][0] = 0;
    //     }
    
    //     for(int i = copyn-1 ; i>=0 ; i--)
    //     {
    //         for(int j = copym-1 ; j>=0 ; j--)
    //         {
    //             for(int k = 1 ; k<=copyk ; k++)
    //             {
                    
    //                 ll include = (ll)nums1[i]* (ll)nums2[j] + next[j+1][k-1];
    //                 ll exc1 = next[j][k];
    //                 ll exc2 = curr[j+1][k];

    //                 curr[j][k] = max<ll>({include,exc1,exc2});
    //             }
    //         }
    //         swap(curr , next);
    //     }
    // return next[0][copyk];
    // }

    ll bytab(int copyn, int copym , int copyk , vector<int>& nums1, vector<int>& nums2)
    {
        vector<vector<vector<ll>>>dp(copyn+1,vector<vector<ll>>(copym+1,vector<ll>(copyk+1,-1e18)));

        for(int i = 0 ; i<=copyn ; i++)
        {
            for(int j = 0 ; j<=copym ; j++)
            {
                dp[i][j][0] = 0;
            }
        }

        for(int i = copyn-1 ; i>=0 ; i--)
        {
            for(int j = copym-1 ; j>=0 ; j--)
            {
                for(int k = 1 ; k<=copyk ; k++)
                {
                    
                    ll include = (ll)nums1[i]* (ll)nums2[j] + dp[i+1][j+1][k-1];
                    ll exc1 = dp[i+1][j][k];
                    ll exc2 = dp[i][j+1][k];

                    dp[i][j][k] = max<ll>({include,exc1,exc2});
                }
            }
        }
    return dp[0][0][copyk];
    }

    ll solve(int i, int j, vector<int>& nums1, vector<int>& nums2, int k, vector<vector<vector<ll>>>&dp){
        // base case
        if(k==0) return 0;
        if(i >= nums1.size() || j >= nums2.size()) return -1e18;

        if(dp[i][j][k] != -1e18) return dp[i][j][k];

        ll include , exc1 , exc2 = 0;
        if(k > 0)
        {
            include = (ll)nums1[i]* (ll)nums2[j] + solve(i+1,j+1,nums1,nums2,k-1,dp);
            exc1 = solve(i+1,j,nums1,nums2,k,dp);
            exc2 = solve(i,j+1,nums1,nums2,k,dp);
        }
        
        return dp[i][j][k] = max<ll>({include,exc1,exc2});
    }

    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<vector<ll>>> dp(n,vector<vector<ll>>(m,vector<ll>(k+1,-1e18)));

        // return solve(0,0,nums1,nums2,k,dp);

        return bytab(n , m , k , nums1 , nums2);

        // return byspaceop(n , m , k , nums1 , nums2);
    }
};