// https://leetcode.com/problems/minimum-deletion-cost-to-make-all-characters-equal

class Solution {
public:
    using pi = pair<int,char>;

    long long minCost(string s, vector<int>& cost) {
        int n = s.size();
        unordered_map<char,int>mp;
        priority_queue<pi , vector<pi> , greater<pi>>pq;

        for(int i = 0 ; i<n ; i++)
        {
            pq.push({cost[i] , s[i]});
            mp[s[i]]++;
        }
        if(mp.size() == 1) return 0;

        int totalcost = 0;
        while(pq.size() > 1)
        {
            auto[cost , ch] = pq.top(); pq.pop();
            totalcost += cost;
        }
        return totalcost;
    }
};