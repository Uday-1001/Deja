// https://leetcode.com/problems/number-of-people-aware-of-a-secret

class Solution {
public:
    const int mod = 1e9+7;

    int peopleAwareOfSecret(int n, int delay, int forget) {
        queue<pair<int,int>>forgetq;
        queue<pair<int,int>>delayq;

        forgetq.push({1,1});
        delayq.push({1,1});

        int active_spreaders = 0;
        int ans = 1;

        for(int i=1 ; i<n ; i++)
        {
            if(!forgetq.empty() && forgetq.front().first + forget <= i)
            {
                //means that the no of active spreaders and the people who know the secret has decreased
                auto front = forgetq.front();
                forgetq.pop();

                active_spreaders = active_spreaders - front.second;
                ans = ans - front.second;
            }

            if(!delayq.empty() && delayq.front().first + delay <= i)
            {
                //means that after the delay days , some people have become active spreaders 
                auto front = delayq.front();
                delayq.pop();
                
                active_spreaders = active_spreaders + front.second;
                ans = ans + front.second;
            }

            if(active_spreaders > 0)
            {
                ans = ans + active_spreaders;
                forgetq.push({i , active_spreaders});
                delayq.push({i , active_spreaders});
            }    
        }
    return ans;
    }
};