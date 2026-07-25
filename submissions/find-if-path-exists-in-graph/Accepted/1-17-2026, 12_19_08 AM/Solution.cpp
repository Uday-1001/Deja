// https://leetcode.com/problems/find-if-path-exists-in-graph

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int , vector<int>>adjlist;

        for(auto it : edges)
        {
            int src = it[0];
            int dest = it[1];
            adjlist[src].push_back(dest);
            adjlist[dest].push_back(src);
        }

        unordered_map<int , bool>vis;
        queue<int>q;
        q.push(source);
        vis[source] = true;

        while(!q.empty())
        {
            int node = q.front(); q.pop();
            for(auto &nbrs : adjlist[node])
            {
                if(!vis[nbrs]) 
                {
                    q.push(nbrs);
                    vis[nbrs] = true;
                }
            }
        }
        return vis[source] == true and vis[destination] == true;
    }
};