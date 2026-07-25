// https://leetcode.com/problems/number-of-provinces

class Solution {
public:
    unordered_map<int , vector<int>>adjlist;
    unordered_map<int, bool>vis;

    void bfs(int src , int n)
    {
        queue<int>q;
        q.push(src);
        vis[src] = true;

        while(!q.empty())
        {
            int front = q.front();
            q.pop();

            for(auto nbr : adjlist[front])
            {
                if(!vis[nbr]) 
                {
                    vis[nbr] = true;
                    q.push(nbr);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int m = isConnected[0].size();

        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                if(isConnected[i][j] == 1 and i != j)
                {
                    adjlist[i].push_back(j);
                }
            }
        }

        int count = 0;
        for(int i = 0 ; i<n ; i++)
        {
            if(!vis[i])
            {
                count++;
                bfs(i , n);
            } 
        }
        return count;
    }
};