// https://leetcode.com/problems/number-of-ways-to-assign-edge-weights-i

class Solution {
public:
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
        
        int rootnode = 1;
        
        int maxdepth = INT_MIN;
        maxdepth = max(maxdepth , DFS(1));

        return pow(2 , maxdepth-1);
    }
};