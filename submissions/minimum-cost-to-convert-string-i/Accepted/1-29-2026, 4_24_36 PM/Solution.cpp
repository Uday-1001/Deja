// https://leetcode.com/problems/minimum-cost-to-convert-string-i

class Solution {
public: 
    using ll = long long;
    using pi = pair<ll , char>;
    unordered_map<int , vector<pair<ll , int>>>adjlist;
    
    void dijkstra(ll src , vector<ll>&mincost)
    {
        mincost[src] = 0;

        priority_queue<pi , vector<pi> , greater<pi>>pq;
        pq.push({0 , src});

        while(!pq.empty())
        {
            auto[cost , node] = pq.top(); pq.pop();

            for(auto it : adjlist[node])
            {
                auto[nbr_cost , nbr] = it;
                if(cost + nbr_cost < mincost[nbr])
                {
                    mincost[nbr] = cost + nbr_cost;
                    pq.push({mincost[nbr] , nbr});
                }
            }
        }
    }

    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n = original.size();
        for(int i = 0 ; i<n ; i++) adjlist[original[i] - 'a'].push_back({cost[i] , changed[i] - 'a'});

        vector<vector<ll>>mincost(26 , vector<ll>(26 , LLONG_MAX));

        for(int i = 0 ; i<26 ; i++) dijkstra(i , mincost[i]);

        ll ans = 0;
        for(int i = 0 ; i <source.size() ; i++)
        {
            if(source[i] == target[i]) continue;
            int u = source[i] - 'a';
            int v = target[i] - 'a';

            if(mincost[u][v] == LLONG_MAX) return -1;
            ans += mincost[u][v];
        }
        return ans;
    }
};