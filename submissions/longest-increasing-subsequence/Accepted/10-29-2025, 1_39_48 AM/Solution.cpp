// https://leetcode.com/problems/longest-increasing-subsequence

class Solution {
public:
    // int recursion(vector<int>&nums , int& last_num_index , int i)
    // {   
    //     if(i >= nums.size()) return 0;

    //     //ek case hum solve karenge
    //     int include = 0;
    //     if(last_num_index == -1 or nums[i] > nums[last_num_index])
    //     {
    //         include = 1 + solve(nums , i , i+1);  
    //     }
    //     int exclude = solve(nums , last_num_index , i+1);
    //     return max(include , exclude);
    // }

        // int bymemo(vector<int>&nums , int& last_num_index , int i , vector<vector<int>>&dp)
        // {
        //     if(i >= nums.size()) return 0;

        //     //index shifting done due to -1 which cannot be represented by array index
        //     if(dp[last_num_index+1][i] != -1) return dp[last_num_index+1][i];

        //     int include = 0;
        //     if(last_num_index == -1 or nums[i] > nums[last_num_index])
        //     {
        //         include = 1 + bymemo(nums , i , i+1 , dp);  
        //     }
        //     int exclude = bymemo(nums , last_num_index , i+1 , dp);
        //     return dp[last_num_index+1][i] = max(include , exclude);
        // }

    int bytab(vector<int>&nums , int n)
    {
        //create a dp array 
        vector<vector<int>>dp(n+1 , vector<int>(n+1 , 0));

        //analyse the base case and update dp array
            //already done as the dp array is initialized with 0 itself 

        //copy and paste the same logic but in dp style using the loops 
        
        //MOST IMPORTANT ->
        //OBSERVATION -> "last_num_index" hamesha "i" ke peeche he to rhega 
        for(int i = n-1 ; i >= 0 ; i--)
        {
            for(int last_num_index = i-1 ; last_num_index >= -1 ; last_num_index--)
            {
                int include = 0;
                if(last_num_index == -1 or nums[i] > nums[last_num_index])
                {
                    include = 1 + dp[i+1][i+1];  
                }
                int exclude = 0 + dp[i+1][last_num_index+1];
                dp[i][last_num_index+1] = max(include , exclude);
            }
        }
        return dp[0][0]; //originally it was dp[0][-1] but because of shifting of rows , +1 is added
    }
    
    int lengthOfLIS(vector<int>& nums) {
        int last_num_index = -1;
        int n = nums.size();
        // vector<vector<int>>dp(n+1 , vector<int>(n+1 , -1));
        // return recursion(nums , last_num_index , 0);
        // return bymemo(nums , last_num_index , 0 , dp);
        return bytab(nums , n);
    }
};