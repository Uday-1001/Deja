// https://leetcode.com/problems/pythagorean-distance-nodes-in-a-tree

class Solution {
public:
    unordered_map<int , vector<pair<int,int>>>adjlist;

    vector<int> bfs(int src , int n)
    {
        vector<int>distances(n , -1);
        distances[src] = 0;
        queue<int>q;
        q.push(src);

        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto &it : adjlist[node]){
                auto[nbr , dist] = it;
                if(distances[nbr] == -1){
                    distances[nbr] = distances[node] + dist;
                    q.push(nbr);
                }
            }
        }
    return distances;
    }
    
    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
        for(auto it : edges){
            int src = it[0];
            int dest = it[1];
            adjlist[src].push_back({dest , 1});
            adjlist[dest].push_back({src , 1});
        }

        auto dx = bfs(x , n);
        // for(auto it : dx) cout<<it<< " ";
        auto dy = bfs(y , n);
        // for(auto it : dy) cout<<it<< " ";
        auto dz = bfs(z , n);
        // for(auto it : dz) cout<<it<< " ";

        vector<int>a = {dx[x] , dx[y] , dx[z]};
        vector<int>b = {dy[x] , dy[y] , dy[z]};
        vector<int>c = {dz[x] , dz[y] , dz[z]};

        int count = 0;
        if(checkPythaTriplet(a)) count++;

        return count;
    }
};