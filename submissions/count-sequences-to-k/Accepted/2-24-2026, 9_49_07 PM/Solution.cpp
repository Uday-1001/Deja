// https://leetcode.com/problems/count-sequences-to-k

class Solution {
public:
    using ti = tuple<int,int,int>;
    using ll = long long;
    map<ti , ll>dp;

    ti factors(ll num)
    {
        int x = 0 , y = 0 , z = 0;
        while(num % 2 == 0) x++ , num /= 2;
        while(num % 3 == 0) y++ , num /= 3;
        while(num % 5 == 0) z++ , num /= 5;

        return {x , y , z};
    }

    int countSequences(vector<int>& nums, long long k) {
        dp[{0 , 0 , 0}] = 1;

        for(auto it : nums)
        {
            auto[fx , fy , fz] = factors(it);
            map<ti , ll>ndp;
            
            for(auto it : dp)
            {
                auto[x , y , z] = it.first;
                auto count = it.second;
                //doing the operations here with powers
                ndp[{x+fx , y+fy , z+fz}] += count;
                ndp[{x-fx , y-fy , z-fz}] += count;
                ndp[{x , y , z}] += count;
            }
            swap(ndp , dp);
        }

    int reqx = 0 , reqy = 0 , reqz = 0;
    ll temp = k;
    while(temp % 2 == 0) reqx++ , temp /= 2;
    while(temp % 3 == 0) reqy++ , temp /= 3;
    while(temp % 5 == 0) reqz++ , temp /= 5;

    if(temp != 1) return 0;
    return dp[{reqx , reqy , reqz}];
    }
};