// https://leetcode.com/problems/greatest-sum-divisible-by-three

class Solution {
public:

    int bymemo(vector<int>&nums , int i , int sum , vector<vector<int>>&dp)
    {
        if(i >= nums.size())
        {
            if(sum % 3 == 0) return sum;
            return INT_MIN;
        }
        if(dp[i][sum] != -1) return dp[i][sum];

        //ek case hum solve karenge 
        int include = bymemo(nums , i+1 , sum + nums[i] , dp);
        int exclude = bymemo(nums , i+1 , sum , dp);

        return dp[i][sum] = max(include , exclude);
    }

    // int byrec(vector<int>&nums , int i , int sum)
    // {
    //     //base case 
    //     if(i >= nums.size())
    //     {
    //         if(sum % 3 == 0) return sum;
    //         return INT_MIN;
    //     }

    //     //ek case hum solve karenge 
    //     int include = byrec(nums , i+1 , sum + nums[i]);
    //     int exclude = byrec(nums , i+1 , sum);

    //     return max(include , exclude);
    // }

    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(begin(nums) , end(nums) , 0);
        // return byrec(nums , 0 , 0);

        vector<vector<int>>dp(n+1 , vector<int>(sum +1 , -1));
        return bymemo(nums , 0 , 0 , dp);
    }
};