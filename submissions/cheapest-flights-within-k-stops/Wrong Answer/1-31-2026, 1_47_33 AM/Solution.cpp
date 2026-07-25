// https://leetcode.com/problems/cheapest-flights-within-k-stops

class Solution {
public:
    using ti = tuple<int,int,int>;
    using pi = pair<int,int>;
    unordered_map<int , vector<pi>>adjlist;

    void dijkstra(int n , int src , int dest , int k , vector<vector<int>>&dist)
    {
        dist[src][0] = 0;

        priority_queue<ti , vector<ti> , greater<>>pq;  
        pq.push({0 , src , 0}); // represents the tuple of {cost , source , stops taken to reach}

        while(!pq.empty())
        {
            auto[main_cost , node , stops] = pq.top();
            pq.pop();

            if(stops > k) continue;

            for(auto &it : adjlist[node])
            {
                auto[cost , nbr] = it;

                if(cost + main_cost < dist[nbr][stops + 1])
                {
                    dist[nbr][stops + 1] = cost + main_cost;
                    pq.push({dist[nbr][stops + 1] , nbr , stops + 1});
                }
            }
        }
    }

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        for(auto it : flights)
        {
            int src = it[0];
            int dest = it[1];
            int cost = it[2];

            adjlist[src].push_back({cost , dest});
        }

        vector<vector<int>>dist(n , vector<int>(k+2 , INT_MAX));
        dijkstra(n , src , dst , k , dist);

        int ans = INT_MAX;
        for(int i = 0 ; i<dist[0].size() ; i++)
        {   
            ans = min(ans , dist[dst][i]);
        }
    return ans;
    }
};