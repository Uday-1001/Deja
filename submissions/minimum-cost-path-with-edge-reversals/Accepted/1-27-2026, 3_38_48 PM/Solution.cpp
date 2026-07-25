// https://leetcode.com/problems/minimum-cost-path-with-edge-reversals

class Solution {
public: 
    using pi = pair<int,int>;
    unordered_map<int , vector<pair<int, int>>>adjlist;

    int dijkstra(int src , int n)
    {
        vector<int>dist(n , INT_MAX);
        priority_queue<pi, vector<pi> , greater<pi>>pq;
        dist[src] = 0;
        pq.push({0 , src});

        while(!pq.empty())
        {
            auto[wt , node] = pq.top(); pq.pop();
            if(node == n-1) return dist[n-1];

            for(auto &it : adjlist[node])
            {
                auto[nbrwt , nbr] = it;
                if(wt + nbrwt < dist[nbr])
                {
                    dist[nbr] = wt + nbrwt;
                    pq.push({dist[nbr] , nbr});
                }
            }
        }
        return dist[n-1] == INT_MAX ? -1 : dist[n-1];
    }

    int minCost(int n, vector<vector<int>>& edges) {
        for(auto it : edges)
        {
            int src = it[0];
            int dest = it[1];
            int wt = it[2];
            adjlist[src].push_back({wt , dest});
            adjlist[dest].push_back({2 * wt , src});
        }

        return dijkstra(0 , n);
    }
};