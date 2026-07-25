// https://leetcode.com/problems/redundant-connection

class Solution {
public:
    vector<int>parent;

    int find(int i)
    {
        if(parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }

    bool Union(int u , int v)
    {
        auto pu = find(u);
        auto pv = find(v);

        if(pu == pv) return false;
        else parent[pu] = pv;

        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n+1);

        iota(parent.begin() , parent.end() , 0);

        for(int i = 0 ; i<n ; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            if(!Union(u , v)) return {u , v};
        }
    return {};
    }
};