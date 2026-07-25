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

    bool bytab(unordered_map<int,int>&mp , vector<int>&stones , int n)
    {
        vector<vector<bool>>dp(n+2 , vector<bool>(n+1 , false));

        for(int row=0 ; row<n+1 ; row++) dp[row][n-1] = true;

        for(int index = n-2 ; index>=0 ; index--)
        {
            for(int jump = n-1 ; jump>=0 ; jump--)
            {
                bool ans = false;
                for(int steps = jump-1 ; steps<=jump+1 ; steps++)
                {
                    if(steps <= 0)continue;

                    int next_stone = stones[index] + steps;

                    if(mp.find(next_stone) != mp.end())
                    {
                        int next_index = mp[next_stone];
                        if(dp[steps][next_index])
                        {
                            ans = true;
                            break;
                        }
                    }
                }
                dp[jump][index] = ans;
            }
        }
    return dp[0][0];
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