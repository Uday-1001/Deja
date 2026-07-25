// https://leetcode.com/problems/max-dot-product-of-two-subsequences

class Solution {
public:
    int byrec(vector<int>& nums1, vector<int>& nums2 , int i , int j , vector<vector<int>>&dp)
    {
        if(i >= nums1.size() or j >= nums2.size()) return INT_MIN;
        if(dp[i][j] != -1) return dp[i][j];

        int include = INT_MIN;
        for(int k = j ; k < nums2.size() ; k++)
        {
            include = max(include , ((nums1[i] * nums2[k]) + max(0 , byrec(nums1 , nums2 , i+1 , k+1 , dp)))); 
        }
        int exclude = 0 + byrec(nums1 , nums2 , i+1 , j , dp);

        return dp[i][j] = max(include , exclude);
    }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        vector<vector<int>>dp(n+1 , vector<int>(m+1 , -1));
        return byrec(nums1 , nums2 , 0 , 0 , dp);
    }
};