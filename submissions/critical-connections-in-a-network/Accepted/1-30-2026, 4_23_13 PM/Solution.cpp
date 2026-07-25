// https://leetcode.com/problems/critical-connections-in-a-network

class Solution {
public:
    unordered_map<int , vector<int>>adjlist;
    unordered_map<int , bool>vis;
    vector<int>low;
    vector<int>tin;

    void TarjansAlgo(int n , int src , int parent , vector<vector<int>>&ans , int timer)
    {
        timer++;
        vis[src] = true;
        tin[src] = timer;
        low[src] = timer;

        for(auto &nbr : adjlist[src])
        {
            if(nbr == parent) continue;
            else if(!vis[nbr])
            {
                TarjansAlgo(n , nbr , src , ans , timer);
                if(low[nbr] > tin[src])
                {
                    vector<int>temp;
                    temp.push_back(src);
                    temp.push_back(nbr);
                    ans.push_back(temp);
                }
            }
            low[src] = min(low[src] , low[nbr]);
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>ans;
        for(auto it : connections)
        {
            adjlist[it[0]].push_back(it[1]);
            adjlist[it[1]].push_back(it[0]);
        }

        tin.resize(n);
        low.resize(n);

        for(int i = 0 ; i<n ; i++)
        {
            if(!vis[i]) TarjansAlgo(n , i , -1 , ans , 0);
        } 
        return ans;
    }
};