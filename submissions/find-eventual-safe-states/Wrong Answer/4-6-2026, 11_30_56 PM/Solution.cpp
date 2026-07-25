// https://leetcode.com/problems/find-eventual-safe-states

class Solution {
public:
    unordered_map<int,vector<int>>adj;
    vector<int>ans;

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        for(int i = 0 ; i<graph.size() ; i++)
        {
            vector<int>it = graph[i];
            if(it.size() == 0) adj[i].push_back(-1);
            else for(auto node : it) adj[i].push_back(node);  
        }
        set<int>st;
        for(auto it : adj)
        {
            if(it.second[0] == -1) st.insert(it.first);
        }

        for(int i = 0 ; i<graph.size() ; i++)
        {
            auto node = i;
            auto vec = adj[node];
            bool flag = true;

            for(auto nbr : vec)
            {
                if(!st.count(nbr)) 
                {
                    flag = false;
                    break;
                }
            }
            if(flag) ans.push_back(node);
        }
        
        for(auto it : st) ans.push_back(it);
        return ans;
    }
};
