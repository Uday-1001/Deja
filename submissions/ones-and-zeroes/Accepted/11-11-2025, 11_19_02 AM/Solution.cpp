// https://leetcode.com/problems/ones-and-zeroes

class Solution {
public:
    static bool mycomp(string &a , string &b)
    {
        return a.size() < b.size();
    }

    pair<int,int> countDigits(string &a)
    {
        int zeros = 0;
        int ones = 0;
        for(auto ch : a)
        {
            if(ch == '0') zeros++;
            else ones++;
        }
        return {zeros , ones};
    }

    int bytab(vector<string>&strs , int m_copy , int n_copy)
    {
        int k = strs.size();
        vector<vector<vector<int>>>dp(m_copy+1, vector<vector<int>>(n_copy+1 , vector<int>(k+1 , 0)));
        
        for(int m = 0 ; m <= m_copy ; m++)
        {
            for(int n = 0 ; n <= n_copy ; n++)
            {
                for(int i = k-1 ; i >= 0 ; i--)
                {
                    string str = strs[i];
                    auto[zero_count , one_count] = countDigits(str);

                    int include = 0;
                    if(m - zero_count >= 0 and n - one_count >= 0)
                    {
                        include = 1 + dp[m - zero_count][n - one_count][i+1];
                    }
                    int exclude = 0 + dp[m][n][i+1];
                    dp[m][n][i] = max(include, exclude);
                }
            }
        }
    return dp[m_copy][n_copy][0];
    }

    // int bymemo(vector<string>&strs , int m , int n , int i , vector<vector<vector<int>>>&dp)
    // {
    //     if(i >= strs.size()) return 0;
    //     if(dp[m][n][i] != -1) return dp[m][n][i];

    //     string str = strs[i];
    //     auto[zero_count , one_count] = countDigits(str);

    //     int include = 0;
    //     if(m - zero_count >= 0 and n - one_count >= 0)
    //     {
    //         include = 1 + bymemo(strs , m - zero_count , n - one_count , i+1 , dp);
    //     }
    //     int exclude = 0 + bymemo(strs , m , n , i+1 , dp);
    //     return dp[m][n][i] = max(include, exclude);
    // }

    // int byrec(vector<string>&strs , int m , int n , int i)
    // {
    //     if(i >= strs.size()) return 0;

    //     string str = strs[i];
    //     auto[zero_count , one_count] = countDigits(str);

    //     int include = 0;
    //     if(m - zero_count >= 0 and n - one_count >= 0)
    //     {
    //         include = 1 + byrec(strs , m - zero_count , n - one_count , i+1);
    //     }
    //     int exclude = 0 + byrec(strs , m , n , i+1);
    //     return max(include, exclude);   
    // }

    int findMaxForm(vector<string>& strs, int m, int n) {
        int k = strs.size();
        sort(strs.begin() , strs.end() , mycomp);
        
        // return byrec(strs , m , n , 0);

        // vector<vector<vector<int>>>dp(m+1, vector<vector<int>>(n+1 , vector<int>(k+1 , -1)));
        // return bymemo(strs , m , n , 0 , dp);

        return bytab(strs , m , n);
    }
};