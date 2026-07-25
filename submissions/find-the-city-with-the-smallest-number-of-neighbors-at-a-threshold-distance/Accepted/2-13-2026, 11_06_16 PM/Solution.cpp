// https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance

class Solution {
public:
    using pi = pair<int,int>;
    unordered_map<int , vector<pi>>adjlist;

    void Dijkstra(int src , int n , int threshold , vector<int>&dist)
    {
        dist[src] = 0;

        priority_queue<pi , vector<pi> , greater<pi>>pq;
        pq.push({0 , src});

        while(!pq.empty())
        {
            auto[wt , node] = pq.top(); pq.pop();

            for(auto it : adjlist[node])
            {
                auto[nbrwt , nbr] = it;
                
                if(nbrwt + wt < dist[nbr])
                {
                    dist[nbr] = nbrwt + wt;
                    pq.push({dist[nbr] , nbr});
                }
            }
        }
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        for(auto it : edges)
        {
            int src = it[0];
            int dest = it[1];
            int wt = it[2];

            adjlist[src].push_back({wt , dest});
            adjlist[dest].push_back({wt , src});
        }

        //running dijkstra for every city and finding the shortest path possible 
        int min_count = INT_MAX;
        int ans = -1;

        for(int src = 0 ; src<n ; src++)
        {
            vector<int>dist(n , INT_MAX);
            Dijkstra(src , n , distanceThreshold , dist);
            int count = 0;
            for(int i = 0 ; i<n ; i++)
            {
                if(i != src and dist[i] <= distanceThreshold) count++;
            }
            //once count is calculated we take out the minimum amoung them
            if(count <= min_count)
            {
                min_count = count;
                ans = max(ans , src);
            }
        }
        return ans;
    }
};