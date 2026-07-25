// https://leetcode.com/problems/minimum-deletion-cost-to-make-all-characters-equal

class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        vector<long long>hash(26 , 0);
        long long total = 0;
        for(int i = 0 ; i<s.size() ; i++)
        {
            hash[s[i] - 'a'] += cost[i];
        }

        int size = 0;
        for(auto it : hash)
        {
            if(it != 0) size++;
        }
        if(size == 1) return 0;
        
        long long ans = 0;
        sort(hash.begin() , hash.end());
        for(int i = 0 ; i<26 ; i++)
        {
            if(hash[i] > 0 && size > 1)
            {
                ans += hash[i];
                size--;
                if(size == 1) break;
            }
        }
    return ans;
    }
};