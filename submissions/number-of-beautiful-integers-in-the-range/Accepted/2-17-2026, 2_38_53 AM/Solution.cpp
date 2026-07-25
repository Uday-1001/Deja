// https://leetcode.com/problems/number-of-beautiful-integers-in-the-range

class Solution {
public:
    int dp[10][2][10][10][2][21];

    int solve(int index , int tight , int even , int odd , bool got_zero , int rem , int k , string &s)
    {
        // base case
        if(index == s.size())
        {
            if(even == odd && rem == 0 && even != 0) return 1;
            return 0;
        }

        if(dp[index][tight][even][odd][got_zero][rem] != -1) return dp[index][tight][even][odd][got_zero][rem];

        int limit = (tight == 1) ? s[index] - '0' : 9;
        int ans = 0;

        for(int i = 0 ; i <= limit ; i++)
        {
            bool new_restriction = (tight && (i == limit));
            bool new_got_zero = (got_zero || (i != 0));

            int even_count = even;
            int odd_count = odd;

            // count digits only after number has started
            if(new_got_zero)
            {
                if(i % 2 == 0) even_count++;
                else odd_count++;
            }

            int new_rem = (rem * 10 + i) % k;

            ans += solve(index + 1 , new_restriction , even_count , odd_count , new_got_zero , new_rem , k , s);
        }

        return dp[index][tight][even][odd][got_zero][rem] = ans;
    }

    int numberOfBeautifulIntegers(int low, int high, int k) {
        memset(dp , -1 , sizeof(dp));
        string l = to_string(low - 1);
        string h = to_string(high);

        int ans_till_low = solve(0 , 1 , 0 , 0 , false , 0 , k , l);

        memset(dp , -1 , sizeof(dp));
        int ans_till_high = solve(0 , 1 , 0 , 0 , false , 0 , k , h);

        return ans_till_high - ans_till_low;
    }
};
