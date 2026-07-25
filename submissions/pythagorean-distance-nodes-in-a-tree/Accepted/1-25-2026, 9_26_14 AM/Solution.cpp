// https://leetcode.com/problems/pythagorean-distance-nodes-in-a-tree

class Solution {
public:
    using ll = long long;
    unordered_map<int , vector<pair<int,int>>>adjlist;

    bool checkPythaTriplet(vector<int>&v)
    {
        sort(v.begin() , v.end());

        if((ll)((ll)v[0]*v[0] + (ll)v[1]*v[1]) == (ll)v[2]*v[2]) return true;
        else return false;
    }

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

        int count = 0;
        for(int i = 0 ; i<n ; i++){
            vector<int>v = {dx[i] , dy[i] , dz[i]};
            if(checkPythaTriplet(v)) count++;
        }

        return count;
    }
};