// https://leetcode.com/problems/longest-balanced-substring-i

class Solution {
public:
    unordered_map<char,int>mp;
    bool isValid(string &s , int i , int j)
    {
        if(mp.empty()) return true;
        auto first_one = mp.begin();

        for(auto &it : mp)
        {
            auto[ch , freq] = it;
            if(freq != first_one->second) return false;
        }
    return true;
    }

    int longestBalanced(string s) {
        int n = s.size();
        if(n == 1) return n;
        int ans = INT_MIN;

        for(int i = 0 ; i<n-1 ; i++)
        {
            mp.clear();
            mp[s[i]]++;

            for(int j = i+1 ; j<n ; j++)
            {
                mp[s[j]]++;
                if(isValid(s , i , j)) 
                {
                    ans = max(ans , j-i+1);
                }
            }
        }
        return ans == INT_MIN ? 0 : ans;
    }
};