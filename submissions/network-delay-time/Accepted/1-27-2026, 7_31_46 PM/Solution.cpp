// https://leetcode.com/problems/network-delay-time

class Solution {
public: 
    using pi = pair<int,int>;
    unordered_map<int , vector<pi>>adjlist;

    void dijkstra(int n , int src , vector<int>&time)
    {
        time[src] = 0;

        priority_queue<pi , vector<pi> , greater<pi>>pq;
        pq.push({0 , src});

        while(!pq.empty())
        {
            auto[wt , node] = pq.top();
            pq.pop();

            for(auto &it : adjlist[node])
            {
                auto[nbrwt , nbr] = it;
                if(wt + nbrwt < time[nbr])
                {
                    time[nbr] = wt + nbrwt;
                    pq.push({time[nbr] , nbr});
                }
            }
        }
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        for(auto it : times)
        {
            int src = it[0];
            int dest = it[1];
            int wt = it[2];

            adjlist[src].push_back({wt , dest});
        }

        vector<int>time(n+1 , INT_MAX);
        dijkstra(n , k , time);

        int ans = 0;
        for(int i = 1 ; i<time.size() ; i++)
        {
            if(time[i] == INT_MAX) return -1;
            ans = max(ans , time[i]);
        }
        return ans;
    }
};