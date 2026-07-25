// https://leetcode.com/problems/number-of-ways-to-assign-edge-weights-i

class Solution {
public:
    using ll = long long;
    int mod = 1e9+7;

    unordered_map<int , vector<int>>adj;

    int DFS(int node)
    {
        int maxi = 0;

        for(auto nbr : adj[node]) maxi = max(maxi , 1 + DFS(nbr));
        return maxi;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size()+1;

        for(auto it : edges) adj[it[0]].push_back(it[1]);
        
        int maxdepth = DFS(1);
        if(maxdepth == 0) return 1;

        ll ans = 1;
        for(int i = 0 ; i<maxdepth-1 ; i++) ans = (ans * 2) % mod;
        return ans;
    }
};