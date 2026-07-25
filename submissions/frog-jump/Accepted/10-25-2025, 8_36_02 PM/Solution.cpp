// https://leetcode.com/problems/frog-jump

class Solution {
public:
    int dp[2001][2001];

    bool solve(unordered_map<int,int>&mp , vector<int>&stones , int jump , int index)
    {
        if(index == stones.size()-1) return true;
        if(jump <= 0) return false;

        if(dp[jump][index] != -1) return dp[jump][index];

        //ek case hum solve karenge , baaki recursion karega
        bool ans = false;
        for(int steps = jump-1 ; steps<=jump+1 ; steps++)
        {
            if(steps <= 0)continue;

            int next_stone = stones[index] + steps;

            if(mp.find(next_stone) != mp.end())
            {
                if(solve(mp , stones , steps , mp[next_stone]))
                {
                    ans = true;
                    break;
                }
            }
        }
    return dp[jump][index] = ans;
    }

    bool canCross(vector<int>& stones) {
        memset(dp , -1 , sizeof(dp));
        unordered_map<int,int>mp;

        for(int i=0 ; i<stones.size() ; i++)
        {
            mp[stones[i]] = i; 
        }

        if(stones.size() >= 2 && stones[1] != 1) return false;

        int jump = 1;
        return solve(mp , stones , jump , mp[jump]);
    }
};