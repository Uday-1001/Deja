// https://leetcode.com/problems/jump-game-iv

class Solution {
public:
    unordered_map<int , vector<int>>adj;
    unordered_map<int , bool>vis;

    int BFS(vector<int>&arr , int i)
    {
        queue<int>q;
        q.push(i);
        vis[i] = true;

        int jumps = 0;
        while(!q.empty())
        {
            int size = q.size();

            while(size--)
            {
                auto front = q.front();
                q.pop();

                if(front == arr.size()-1) return jumps;

                int next = (front+1 < arr.size()) ? front+1 : -1;
                if(!vis[next] and next != -1)
                {
                    vis[next] = true;
                    q.push(next);
                } 

                int prev = (front-1 >= 0) ? front-1 : -1;
                if(!vis[prev] and prev != -1) 
                {
                    q.push(prev);
                    vis[prev] = true;
                }

                for(auto &nbr : adj[arr[front]])
                {
                    if(!vis[nbr] and nbr != front)
                    {
                        int ditto = nbr;
                        q.push(ditto);
                        vis[ditto] = true;
                    }
                }   
            }
            jumps++;
        }
        return -1;
    }

    int minJumps(vector<int>& arr) {
        for(int i = 0 ; i<arr.size() ; i++) adj[arr[i]].push_back(i);

        return BFS(arr , 0);
    }
};