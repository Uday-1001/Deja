// https://leetcode.com/problems/path-existence-queries-in-a-graph-i

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<bool>ans;
        vector<int>component(n ,-1);
        component[0] = 0;

        for(int i = 1 ; i<n ; i++)
        {
            if((nums[i] - nums[i-1]) <= maxDiff) component[i] = component[i-1];
            else component[i] = (component[i-1] == -1) ? 0 : (component[i-1] + 1);
        }

        for(auto it : queries)
        {
            int u = it[0];
            int v = it[1];

            if((u == v) or (component[u] == component[v])) ans.push_back(true);
            else ans.push_back(false);
        }
        
        return ans;
    }
};