// https://leetcode.com/problems/maximum-alternating-subsequence-sum

class Solution {
public:
    typedef long long ll;
    // vector<vector<ll>>dp;

    ll bytab(vector<int>&nums)
    {
        int n = nums.size();
        vector<vector<ll>>dp(n+1 , vector<ll>(3 , 0));

        for(int i = n-1 ; i >= 0 ; i--)
        {
            for(int flag = 0 ; flag < 2 ; flag++)
            {
                ll include = 0;
                if(flag == true)
                {
                    ll even_sum = nums[i] + dp[i+1][1-flag];
                    include = max<ll>(include , even_sum);
                }
                else
                {
                    ll odd_sum = -nums[i] + dp[i+1][1-flag];
                    include = max<ll>(include , odd_sum);
                }
                ll exclude = 0 + dp[i+1][flag];

            dp[i][flag] = max<ll>(include , exclude);
            }
        }
    return dp[0][1];  
    }

    // ll bymemo(vector<int>&nums , bool flag , int i)
    // {
    //     if(i >= nums.size()) return 0;
    //     if(dp[i][flag] != -1) return dp[i][flag];
        
    //     //ek case hum solve karenge
    //     ll include = 0;
    //     if(flag == true)
    //     {
    //         ll even_sum = nums[i] + bymemo(nums , !flag , i+1);
    //         include = max<ll>(include , even_sum);
    //     }
    //     else
    //     {
    //         ll odd_sum = -nums[i] + bymemo(nums , !flag , i+1);
    //         include = max<ll>(include , odd_sum);
    //     }
    //     ll exclude = 0 + bymemo(nums , flag , i+1);

    //     return dp[i][flag] = max<ll>(include , exclude);
    // }

    // long long byrec(vector<int>&nums , bool flag , int i)
    // {
    //     if(i >= nums.size()) return 0;
        
    //     //ek case hum solve karenge
    //     long long even_sum = 0;
    //     long long odd_sum = 0;
    //     long long include = 0;
    //     if(flag == true)
    //     {
    //         even_sum = nums[i] + byrec(nums , !flag , i+1);
    //         include = max(include , even_sum);
    //     }
    //     else
    //     {
    //         odd_sum = -nums[i] + byrec(nums , !flag , i+1);
    //         include = max(include , odd_sum);
    //     }
    //     long long exclude = 0 + byrec(nums , flag , i+1);

    //     return max(include , exclude);
    // }   

    long long maxAlternatingSum(vector<int>& nums) {    
        // return byrec(nums , true , 0);

        // int n = nums.size();
        // dp.resize(n + 1 , vector<ll>(3 , -1));
        // return bymemo(nums , true , 0);

        return bytab(nums);

    }
};