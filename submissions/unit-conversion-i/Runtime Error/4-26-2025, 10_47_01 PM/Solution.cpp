// https://leetcode.com/problems/unit-conversion-i

class Solution {
public:

    unordered_map<int,vector<pair<int,int>>>adj;


    void dfs(vector<int>& ans, int src){
        // nbr call karenge
        for(auto nbr : adj[src]){
            ans[nbr.first] = ans[src] * nbr.second;
            dfs(ans, nbr.first);
        }
    }

    vector<int> baseUnitConversions(vector<vector<int>>& conversions) {
        //adjacency list
        for(auto entry : conversions)
        {
            adj[entry[0]].push_back({entry[1] , entry[2]});
        }
        vector<int>ans(conversions.size()+1);
        ans[0] = 1;
        dfs(ans, 0);

        return ans;

    }
};