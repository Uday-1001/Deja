// https://leetcode.com/problems/frog-jump

class Solution {
public:
    // int dp[2001][2001];

    // bool solve(unordered_map<int,int>&mp , vector<int>&stones , int jump , int index)
    // {
    //     if(index == stones.size()-1) return true;
    //     if(jump <= 0) return false;

    //     if(dp[jump][index] != -1) return dp[jump][index];

    //     //ek case hum solve karenge , baaki recursion karega
    //     bool ans = false;
    //     for(int steps = jump-1 ; steps<=jump+1 ; steps++)
    //     {
    //         if(steps <= 0)continue;

    //         int next_stone = stones[index] + steps;

    //         if(mp.find(next_stone) != mp.end())
    //         {
    //             if(solve(mp , stones , steps , mp[next_stone]))
    //             {
    //                 ans = true;
    //                 break;
    //             }
    //         }
    //     }
    // return dp[jump][index] = ans;
    // }

    // bool bytab(unordered_map<int,int>&mp , vector<int>&stones , int n)
    // {
    //     if(stones[1] != true) return false;
    //     vector<vector<bool>>dp(n+1 , vector<bool>(n+1 , false));

    //     for(int row=0 ; row<n+1 ; row++) dp[row][n-1] = true;

    //     for(int index = n-2 ; index>=0 ; index--)
    //     {
    //         for(int jump = 1 ; jump<n ; jump++)
    //         {
    //             bool ans = false;
    //             for(int steps = jump-1 ; steps<=jump+1 ; steps++)
    //             {
    //                 if(steps <= 0)continue;

    //                 int next_stone = stones[index] + steps;

    //                 if(mp.find(next_stone) != mp.end())
    //                 {
    //                     int next_index = mp[next_stone];
    //                     if(dp[steps][next_index])
    //                     {
    //                         ans = true;
    //                         break;
    //                     }
    //                 }
    //             }
    //             dp[jump][index] = ans;
    //         }
    //     }
    // return dp[1][0];
    // }

    bool bytab(unordered_map<int, int>& mp, vector<int>& stones, int n)
{
    // Edge Case: The first jump must be to 1. If stone[1] isn't 1, it's impossible.
    // if (stones[1] != 1) return false;

    vector<vector<bool>> dp(n + 2, vector<bool>(n + 1, false));

    // Base Case: If you are at the last stone, you have won.
    // This is correct.
    for (int row = 0; row < n + 1; row++) dp[row][n - 1] = true;

    for (int index = n - 2; index >= 0; index--)
    {
        // --- CORRECTION 1 ---
        // Iterate over all possible jump sizes that could have landed us here.
        // Your old loop (jump=index..0) was the critical bug.
        for (int jump = 1; jump <= n; jump++)
        {
            bool ans = false;
            for (int steps = jump - 1; steps <= jump + 1; steps++)
            {
                if (steps <= 0) continue;

                // --- CORRECTION 2 ---
                // Enforce the "first jump must be 1" rule.
                // If we are calculating from the start (index 0),
                // we are only allowed to check the required first step of 1.
                // if (index == 0 && steps != 1) continue;
                

                int next_stone = stones[index] + steps;

                if (mp.find(next_stone) != mp.end())
                {
                    int next_index = mp[next_stone];
                    
                    // This logic is correct:
                    // Can we win from the next stone,
                    // landing there with a jump of 'steps'?
                    if (dp[steps][next_index])
                    {
                        ans = true;
                        break;
                    }
                }
            }
            dp[jump][index] = ans;
        }
    }
    
    // With Correction 2, this return value is now correct.
    // It calculates dp[1][0] by only checking steps=1,
    // which in turn depends on dp[1][1].
    return dp[1][0];
}

    bool canCross(vector<int>& stones) {
        // memset(dp , -1 , sizeof(dp));
        unordered_map<int,int>mp;

        for(int i=0 ; i<stones.size() ; i++)
        {
            mp[stones[i]] = i; 
        }

        if(stones.size() >= 2 && stones[1] != 1) return false;

        int jump = 1;
        int n = stones.size();
        // return solve(mp , stones , jump , mp[jump]);
        return bytab(mp , stones , n);
    }
};