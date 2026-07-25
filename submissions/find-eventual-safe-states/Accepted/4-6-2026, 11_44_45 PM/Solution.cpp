// https://leetcode.com/problems/find-eventual-safe-states

class Solution {
public:
    unordered_map<int,vector<int>>adj;
    vector<int>ans;
    unordered_map<int,int>outdegree;

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        for(int i = 0 ; i<graph.size() ; i++)
        {
            vector<int>it = graph[i]; 
            outdegree[i] = it.size();

            for(auto nbr : it) adj[nbr].push_back(i);  
        }

        queue<int>q;
        for(int i = 0 ; i<graph.size() ; i++) if(outdegree[i] == 0) q.push(i);

        while(!q.empty())
        {
            auto node = q.front();
            q.pop();

            ans.push_back(node);

            for(auto &nbr : adj[node])
            {
                outdegree[nbr]--;
                if(outdegree[nbr] == 0) q.push(nbr);
            }
        }
        
        sort(begin(ans) , end(ans));
        return ans;
    }
};
