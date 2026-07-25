// https://leetcode.com/problems/partition-equal-subset-sum

class Solution {
public:
     bool byspace_op2(vector<int>&nums , int copy_target)
    {
        int n = nums.size();
        vector<int>curr(copy_target+1 , 0);

        curr[0] = true;

        for(int i = n-1 ; i>=0 ; i--)
        {
            for(int target = copy_target ; target>=0 ; target--)
            {
                bool include = false;
                if(target - nums[i] >= 0)
                {
                    include = curr[target-nums[i]];
                }
                bool exclude = curr[target];
                curr[target] = include || exclude;
            }
        }
    return curr[copy_target];
    }

    // bool byspace_op1(vector<int>&nums , int copy_target)
    // {
    //     int n = nums.size();
    //     vector<int>curr(copy_target+1 , 0);
    //     vector<int>next(copy_target+1 , 0);

    //     curr[0] = next[0] = true;

    //     for(int i = n-1 ; i>=0 ; i--)
    //     {
    //         for(int target = 1 ; target<=copy_target ; target++)
    //         {
    //             bool include = false;
    //             if(target - nums[i] >= 0)
    //             {
    //                 include = next[target-nums[i]];
    //             }
    //             bool exclude = next[target];
    //             curr[target] = include || exclude;
    //         }
    //         next = curr;
    //     }
    // return curr[copy_target];
    // }

    // bool bytab(vector<int>&nums , int copy_target)
    // {
    //     int n = nums.size();
    //     vector<vector<int>>dp(copy_target+1 , vector<int>(n+1 , 0));

    //     for(int col=0 ; col<=n ; col++)
    //     {
    //         dp[0][col] = true;
    //     }

    //     for(int target=1 ; target<=copy_target ; target++)
    //     {
    //         for(int i=n-1 ; i>=0 ; i--)
    //         {
    //             bool include = false;
    //             if(target - nums[i] >= 0) include = dp[target-nums[i]][i+1];
    //             bool exclude = dp[target][i+1];

    //             dp[target][i] = include || exclude;
    //         }
    //     }
    // return dp[copy_target][0];
    // }

    // bool bymemo(vector<int>&nums , int target , int i , vector<vector<int>>&dp)
    // {
    //     if(i >= nums.size() || target < 0) return false;
    //     if(target == 0) return true;

    //     if(dp[target][i] != -1) return dp[target][i];

    //     int include = bymemo(nums , target-nums[i] , i+1 , dp);
    //     int exclude = bymemo(nums , target , i+1 , dp);

    //     return dp[target][i] = include || exclude;
    // }

    // bool byrec(vector<int>&nums , int target , int i)
    // {
    //     //base case 
    //     if(target == 0) return true;
    //     if(i >= nums.size() or target < 0) return false;

    //     int include = byrec(nums , target-nums[i] , i+1);
    //     int exclude = byrec(nums , target , i+1);

    //     return include || exclude;
    // }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(begin(nums) , end(nums) , 0);

        if(sum & 1) return false;
        int target = sum / 2;

        // return byrec(nums , target , 0);

        // vector<vector<int>>dp(target+1 , vector<int>(n+1 , -1));
        // return bymemo(nums , target , 0 , dp);

        // return bytab(nums , target);

        // return byspace_op1(nums , target);

        return byspace_op2(nums , target);
    }
};