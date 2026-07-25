// https://leetcode.com/problems/longest-increasing-subsequence

class Solution {
public:
    int byspace_op2(vector<int>&nums)
    {
        int n = nums.size();
        vector<int>curr(n+1 , 0);

        for(int i = n-1 ; i >= 0 ; i--)
        {
            for(int last_num_index = i-1 ; last_num_index >= -1 ; last_num_index--)
            {
                int include = 0;
                if(last_num_index == -1 or nums[i] > nums[last_num_index])
                {
                    include = 1 + curr[i+1];  
                }
                int exclude = 0 + curr[last_num_index+1];
                curr[last_num_index+1] = max(include , exclude);
            }
        }
        return curr[0];
    }
    
    // int byspace_op1(vector<int>&nums)
    // {
    //     int n = nums.size();
    //     vector<int>curr(n+1 , 0);
    //     vector<int>next(n+1 , 0);

    //     for(int i = n-1 ; i >= 0 ; i--)
    //     {
    //         for(int last_num_index = i-1 ; last_num_index >= -1 ; last_num_index--)
    //         {
    //             int include = 0;
    //             if(last_num_index == -1 or nums[i] > nums[last_num_index])
    //             {
    //                 include = 1 + next[i+1];  
    //             }
    //             int exclude = 0 + next[last_num_index+1];
    //             curr[last_num_index+1] = max(include , exclude);
    //         }
    //         //shifting the rows 
    //         next = curr;
    //     }
    //     return curr[0];
    // }

    // int bytab(vector<int>&nums , int n)
    // {
    //     //create a dp array 
    //     vector<vector<int>>dp(n+1 , vector<int>(n+1 , 0));

    //     //analyse the base case and update dp array
    //         //already done as the dp array is initialized with 0 itself 

    //     //copy and paste the same logic but in dp style using the loops 
        
    //     //MOST IMPORTANT ->
    //     //OBSERVATION -> "last_num_index" hamesha "i" ke peeche he to rhega 
    //     for(int i = n-1 ; i >= 0 ; i--)
    //     {
    //         for(int last_num_index = i-1 ; last_num_index >= -1 ; last_num_index--)
    //         {
    //             int include = 0;
    //             if(last_num_index == -1 or nums[i] > nums[last_num_index])
    //             {
    //                 include = 1 + dp[i+1][i+1];  
    //             }
    //             int exclude = 0 + dp[i+1][last_num_index+1];
    //             dp[i][last_num_index+1] = max(include , exclude);
    //         }
    //     }
    //     return dp[0][0]; //originally it was dp[0][-1] but because of shifting of rows , +1 is added
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

    // int byrec(vector<int>&nums , int& last_num_index , int i)
    // {   
    //     if(i >= nums.size()) return 0;

    //     //ek case hum solve karenge
    //     int include = 0;
    //     if(last_num_index == -1 or nums[i] > nums[last_num_index])
    //     {
    //         include = 1 + byrec(nums , i , i+1);  
    //     }
    //     int exclude = byrec(nums , last_num_index , i+1);
    //     return max(include , exclude);
    // }
    
    int lengthOfLIS(vector<int>& nums) {
        int last_num_index = -1;
        int n = nums.size();

        // return byrec(nums , last_num_index , 0);

        // vector<vector<int>>dp(n+1 , vector<int>(n+1 , -1));
        // return bymemo(nums , last_num_index , 0 , dp);

        // return bytab(nums , n);

        // return byspace_op1(nums);

        return byspace_op2(nums);
    }
};