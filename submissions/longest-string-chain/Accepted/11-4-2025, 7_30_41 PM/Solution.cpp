// https://leetcode.com/problems/longest-string-chain

class Solution {
public:
    static bool mycomparator(string &w1 , string &w2)
    {
        return w1.size() < w2.size();
    }

    bool isPredecessor(string prev , string curr)
    {
        int diff_in_size = curr.size() - prev.size();
        if(diff_in_size != 1) return false;

        int i=0 ; int j=0;
        while(i <prev.size() && j < curr.size())
        {
            if(prev[i] == curr[j]) 
                i++;
            j++;
        }
        return (i == prev.size());
    }
    int bymemo(vector<string>&words , int prev , int curr , vector<vector<int>>&dp)
    {
        if(curr >= words.size()) return 0;
        if(dp[prev+1][curr] != -1) return dp[prev+1][curr];

        //ek case hum solve karenge 
        int include = 0;
        if(prev == -1 || isPredecessor(words[prev] , words[curr]))
        {
            include = 1 + bymemo(words , curr , curr+1 , dp);
        }
        int exclude = 0 + bymemo(words , prev , curr+1 , dp);

        return dp[prev+1][curr] = max(include , exclude);
    }

    // int byrec(vector<string>&words , int prev , int curr)
    // {
    //     ///base case 
    //     if(curr >= words.size()) return 0;

    //     //ek case hum solve karenge 
    //     int include = 0;
    //     if(prev == -1 || isPredecessor(words[prev] , words[curr]))
    //     {
    //         include = 1 + byrec(words , curr , curr+1);
    //     }
    //     int exclude = 0 + byrec(words , prev , curr+1);

    //     return max(include , exclude);
    // } 

    int longestStrChain(vector<string>& words) {
        sort(begin(words) , end(words) , mycomparator);
        // return byrec(words , -1 , 0);

        int n = words.size();
        vector<vector<int>>dp(n+1 , vector<int>(n+1 , -1));
        return bymemo(words , -1 , 0 , dp);
    }
};