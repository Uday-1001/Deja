// https://leetcode.com/problems/max-dot-product-of-two-subsequences

class Solution {
public:
    int bytab(vector<int>& nums1, vector<int>& nums2 , int n , int m)
    {
        vector<vector<int>>dp(n+1 , vector<int>(m+1 , INT_MIN));

        for(int i = n-1 ; i>=0 ; i--)
        {
            for(int j = m-1 ; j>=0 ; j--)
            {
                int include = INT_MIN;
                for(int k = j ; k < nums2.size() ; k++)
                {
                    include = max(include , ((nums1[i] * nums2[k]) + max(0 , dp[i+1][k+1]))); 
                }
                int exclude = 0 + dp[i+1][j];

                dp[i][j] = max(include , exclude);
            }
        }
    return dp[0][0];
    }

    // int byrec(vector<int>& nums1, vector<int>& nums2 , int i , int j , vector<vector<int>>&dp)
    // {
    //     if(i >= nums1.size() or j >= nums2.size()) return INT_MIN;
    //     if(dp[i][j] != -1) return dp[i][j];

    //     int include = INT_MIN;
    //     for(int k = j ; k < nums2.size() ; k++)
    //     {
    //         include = max(include , ((nums1[i] * nums2[k]) + max(0 , byrec(nums1 , nums2 , i+1 , k+1 , dp)))); 
    //     }
    //     int exclude = 0 + byrec(nums1 , nums2 , i+1 , j , dp);

    //     return dp[i][j] = max(include , exclude);
    // }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        // vector<vector<int>>dp(n+1 , vector<int>(m+1 , -1));
        // return byrec(nums1 , nums2 , 0 , 0 , dp);

        return bytab(nums1 , nums2 , n , m);
    }
};