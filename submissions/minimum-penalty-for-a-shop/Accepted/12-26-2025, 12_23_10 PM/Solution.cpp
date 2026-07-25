// https://leetcode.com/problems/minimum-penalty-for-a-shop

class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        int ans = INT_MAX;
        int best_hour = -1;

        vector<int>closing(n , 0);
        vector<int>opening(n , 0);

        vector<int>prefix_close(n + 1 , 0);
        prefix_close[0] = 0;

        vector<int>prefix_open(n + 1 , 0);
        prefix_open[0] = 0;

        for(int i = 0 ; i < n ; i++)
        {
            char ch = customers[i];
            if(ch == 'Y')
            {
                closing[i] = 1;
                opening[i] = 0;
            } 
            else 
            {
                closing[i] = 0;
                opening[i] = 1;
            }
        }

        for(int i = 1 ; i<=n ; i++)
        {
            prefix_close[i] = prefix_close[i-1] + closing[i-1];
            prefix_open[i] = prefix_open[i-1] + opening[i-1];
        }

        for(int i = 0 ; i<=n ; i++)
        {
            int penalty_occured = (prefix_close[n] - prefix_close[i]) + prefix_open[i];
            if(penalty_occured < ans)
            {
                ans = penalty_occured;
                best_hour = i;
            }
        }

        return best_hour;
    }
};