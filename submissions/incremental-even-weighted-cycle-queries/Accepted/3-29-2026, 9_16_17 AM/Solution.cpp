// https://leetcode.com/problems/incremental-even-weighted-cycle-queries

class Solution {
public:
    vector<int>parent;
    vector<int>sum;
    
    int find(int i)
    {
        if(parent[i] == i) return i;
        int root = parent[i];
        parent[i] = find(parent[i]);
        sum[i] = (sum[i] + sum[root]) % 2;
        return parent[i];
    }

    bool Union(int u , int v , int w){
        int pu = find(u);
        int pv = find(v);

        if(pu == pv){
            return ((sum[u] + sum[v]) % 2) == (w % 2);
        }
        parent[pu] = pv;
        sum[pu] = (sum[u] + sum[v] + w) % 2;
        return true;
    }
    
    int numberOfEdgesAdded(int n, vector<vector<int>>& edges) {
        parent.resize(n , 0);
        sum.resize(n , 0);
        
        for(int i = 0 ; i<n ; i++){
            parent[i] = i;
        }

        int count = 0;
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            if(Union(u , v , w)) count++;
        }
        return count; 
    }
};