// https://leetcode.com/problems/maximum-value-of-concatenated-binary-segments

class Solution {
public:
    using pi = pair<int,int>;
    int mod = 1e9 + 7;

    static bool mycomp(const pair<int,int>&a , const pair<int,int>&b)
    {
        if(a.first == b.first) return a.second > b.second;
        return a.first > b.first;
    }

    long long binaryToDecimal(string &s)
    {
        long long ans = 0;
        for(int i = 0 ; i<s.size() ; i++)
        {
            ans = (((ans * 2) % mod) + (s[i] - '0')) % mod;
        }
        return ans % mod;
    }

    int maxValue(vector<int>& nums1, vector<int>& nums0) {
        vector<pi>pairs;
        for(int i = 0 ; i<nums1.size() ; i++) pairs.push_back({nums1[i] , nums0[i]});

        sort(begin(pairs) , end(pairs) , mycomp);

        string formed = "";
        for(auto it : pairs)
        {
            auto[ones , zeros] = it;
            while(ones--) formed += '1';
            while(zeros--) formed += '0';
        }

        return binaryToDecimal(formed) % mod;
    }
};