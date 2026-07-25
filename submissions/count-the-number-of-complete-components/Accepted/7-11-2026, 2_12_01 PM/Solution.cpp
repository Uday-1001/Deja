// https://leetcode.com/problems/count-the-number-of-complete-components

class Solution {
public:
    unordered_map<int , vector<int>>adj;

    void DFS(int src , int component_id , vector<int>&components)
    {
        components[src] = component_id;

        for(auto nbr : adj[src])
        {
            if(components[nbr] == -1) DFS(nbr , component_id , components);
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        for(auto it : edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int>components(n , -1);
        
        int component_id = 0;
        for(int i = 0 ; i<n ; i++)
        {
            if(components[i] == -1)
            {
                DFS(i , component_id , components);
                component_id++;
            }
        }

        vector<int>vertices(component_id , 0);
        vector<int>edgeCount(component_id , 0);

        for(int i = 0 ; i<n ; i++) vertices[components[i]]++;

        for(auto it : edges) edgeCount[components[it[0]]]++;

        int ans = 0;
        for(int i = 0 ; i<component_id ; i++)
        {
            if(edgeCount[i] == ((vertices[i] * (vertices[i]-1)) / 2)) ans++;
        }
        
        return ans;
    }
};