// https://leetcode.com/problems/minimum-cost-tree-from-leaf-values

class Solution {
public:
    int bymemo(vector<int>&arr , map<pair<int,int> , int>&maxvals , int start , int end , vector<vector<int>>&dp)
    {
        //base case 
        if(start >= end) return 0;
        if(dp[start][end] != -1) return dp[start][end];

        int ans = INT_MAX;
        for(int i = start ; i < end ; i++)
        {
            int leftmaxval = maxvals[{start , i}];
            int rightmaxval = maxvals[{i+1 , end}];
            int totalleafval = leftmaxval * rightmaxval;

            int leftrecursiveans = bymemo(arr , maxvals , start , i , dp);
            int rightrecursiveans = bymemo(arr , maxvals , i+1 , end , dp);

            int totalrecursiveans = totalleafval + leftrecursiveans + rightrecursiveans;
            ans = min(ans , totalrecursiveans);
        }
        return dp[start][end] = ans;
    }

    // int byrec(vector<int>&arr , map<pair<int,int> , int>&maxvals , int start , int end)
    // {
    //     //base case 
    //     if(start >= end) return 0;

    //     //ek case hum solve krenge
    //     int ans = INT_MAX;
    //     for(int i = start ; i < end ; i++)
    //     {
    //         int leftmaxval = maxvals[{start , i}];
    //         int rightmaxval = maxvals[{i+1 , end}];
    //         int totalleafval = leftmaxval * rightmaxval;

    //         int leftrecursiveans = byrec(arr , maxvals , start , i);
    //         int rightrecursiveans = byrec(arr , maxvals , i+1 , end);

    //         int totalrecursiveans = totalleafval + leftrecursiveans + rightrecursiveans;
    //         ans = min(ans , totalrecursiveans);
    //     }
    //     return ans;
    // }

    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        map<pair<int,int> , int>maxvals;
        for(int i = 0; i<arr.size() ; i++)
        {
            for(int j = i; j<arr.size() ; j++)
            {
                if(i == j) maxvals[{i , j}] = arr[i];
                else
                maxvals[{i , j}] = max(maxvals[{i , j-1}] , arr[j]);
            }
        }
        // return byrec(arr , maxvals , 0 , n-1);

        vector<vector<int>>dp(n+1 , vector<int>(n+1 , -1));
        return bymemo(arr , maxvals , 0 , n-1 , dp);
    }
};