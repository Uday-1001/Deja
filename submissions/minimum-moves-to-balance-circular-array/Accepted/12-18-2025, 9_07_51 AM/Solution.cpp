// https://leetcode.com/problems/minimum-moves-to-balance-circular-array

class Solution {
public:

    using ll = long long;

    long long minMoves(vector<int>& balance) {
        int n = balance.size();
        if(n == 1) return balance[0] < 0 ? -1 : 0;

        int negative_index = -1;
        int negative_val = -1;
        for(int i = 0; i<n; i++)
        {
            if(balance[i] < 0)
            {
                negative_index = i;
                negative_val = balance[i];
            }
        }

        if(negative_index == -1) return 0;

        int l = (negative_index - 1 + n) % n;
        int r = (negative_index + 1) % n;

        int rem = n - 1;
        int visited = 0;
        ll distance = 1;
        ll ans = 0;

        while(visited < rem and negative_val < 0){
            if(l == r)
            {
                if(abs(negative_val) > balance[l])
                {
                    ans += balance[l] * distance;
                    negative_val += balance[l];
                }
                else 
                {
                    ans += (abs(negative_val) * distance);
                    negative_val = 0;
                }
            }
            else
            {
                if(abs(negative_val) > (balance[l] + balance[r]))
                {
                    ans += (balance[l] + balance[r]) * distance;
                    negative_val += (balance[l] + balance[r]);
                }
                else
                {
                    ans += (abs(negative_val) * distance);
                    negative_val = 0;
                }
            }
            distance++;
            visited += 2;
            l = (l - 1 + n) % n;
            r = (r + 1) % n;
        } 

        if(negative_val < 0) return -1;

        return ans;

    }
};