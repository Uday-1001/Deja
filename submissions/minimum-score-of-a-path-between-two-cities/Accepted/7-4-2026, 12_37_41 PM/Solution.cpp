// https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities

class Solution {
public:
    unordered_map<int, vector<pair<int,int>>> adj;
    unordered_map<int,bool>vis;
    int ans = INT_MAX;

    void DFS(int src)
    {
        vis[src] = true;

        for(auto [nbr, wt] : adj[src])
        {
            ans = min(ans, wt);
            if(!vis[nbr]) DFS(nbr);
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {
        for(auto &it : roads)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        DFS(1);
        return ans;
    }
};