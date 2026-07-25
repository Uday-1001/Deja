// https://leetcode.com/problems/cheapest-flights-within-k-stops

class Solution {
public:
    using pi = pair<int,int>;
    unordered_map<int, vector<pi>>adjlist;

    void dijkstra(int n , int src , int k , vector<int>&price)
    {
        price[src] = 0;

        priority_queue<pi , vector<pi> , greater<pi>>pq;
        pq.push({0 , src});

        while(!pq.empty())
        {
            auto[base_fare , node] = pq.top();

            pq.pop();

            for(auto &it : adjlist[node])
            {
                auto[price_nbr , nbr] = it;
                if(k > 0 and price_nbr + base_fare < price[nbr])
                {
                    price[nbr] = price_nbr + base_fare;
                    k--;
                    pq.push({price[nbr] , nbr});
                }
                else k++;
            }
        }
    }

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        for(auto it : flights)
        {
            int src = it[0];
            int dest = it[1];
            int fare = it[2];

            adjlist[src].push_back({fare , dest});
        }

        vector<int>price(n , INT_MAX);

        dijkstra(n , src , k , price);
        return price[dst];
    }
};