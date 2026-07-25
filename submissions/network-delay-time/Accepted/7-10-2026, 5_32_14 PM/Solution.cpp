// https://leetcode.com/problems/network-delay-time

class Solution {
public:
    using pi = pair<int,int>;
    vector<int>dist;
    unordered_map<int,vector<pair<int,int>>>adj;

    void DijkstraAlgo(int src)
    {
        dist[src] = 0;
        priority_queue<pi , vector<pi> , greater<pi>>pq;

        pq.push({0 , src});
        while(!pq.empty())
        {
            auto [wt , node] = pq.top();
            pq.pop();

            for(auto nbr : adj[node])
            {
                auto[nbrwt , nbrnode] = nbr;
                if(wt + nbrwt < dist[nbrnode])
                {
                    dist[nbrnode] = wt + nbrwt;
                    pq.push({dist[nbrnode] , nbrnode});
                }
            }
        }
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        dist.resize(n+1 , INT_MAX);

        for(auto it : times)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adj[u].push_back({wt , v});
        }

        DijkstraAlgo(k);

        int mintime = -1;
        for(int i = 1 ; i<=n ; i++) 
        {
            if(dist[i] == INT_MAX) return -1;
            mintime = max(mintime , dist[i]);
        }
        return mintime;
    }
};