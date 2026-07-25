// https://leetcode.com/problems/minimum-edge-reversals-so-every-node-is-reachable

class Solution {
public:
    int totalcost = 0;
    int size;
    unordered_map<int , bool>vis;
    unordered_map<int , vector<pair<int,int>>>adj;
    vector<int>cost;
    vector<int>depth;

    void DFS(int node , int parent , int d)
    {
        vis[node] = true;
        depth[node] = d;
        for(auto &nbr : adj[node])
        {
            int neighbour = nbr.first;
            int costofNbr = nbr.second;

            if(!vis[neighbour])
            {
                cost[neighbour] = cost[node] + costofNbr;
                totalcost += costofNbr;
                DFS(neighbour , node , d + 1);
            }
        }
    }

    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        vector<int>ans(n);
        cost.assign(n , 0);
        depth.assign(n , 0);

        for(auto it : edges)
        {
            int u = it[0];
            int v = it[1];

            adj[u].push_back({v , 0});
            adj[v].push_back({u , 1});
        }

        DFS(0 , -1 , 0);
        
        ans[0] = totalcost;
        for(int i = 1 ; i<n ; i++)
        {
            int reversing_cost = abs(cost[i] - depth[i]);
            int this_path_cost = abs(cost[i] - totalcost);

            ans[i] = reversing_cost + this_path_cost;
        }
        return ans;
    }
};