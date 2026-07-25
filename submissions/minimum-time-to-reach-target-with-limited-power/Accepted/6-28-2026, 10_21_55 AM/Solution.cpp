// https://leetcode.com/problems/minimum-time-to-reach-target-with-limited-power

class Solution {
public:
    using ll = long long;
    using ti = tuple<ll,int,int>;
    unordered_map<int , vector<pair<int,int>>>adj;
    vector<vector<ll>>dist;
    vector<ll>ans;

    void Dijkstra(int n , int power , vector<int>&cost , int src , int target)
    {
        dist[src][power] = 0;
        priority_queue<ti , vector<ti> , greater<ti>>pq;
        pq.push({0 , src , power});

        while(!pq.empty())
        {
            auto[time , node , power] = pq.top();
            pq.pop();

            if(power < cost[node]) continue;
            
            int newpower = power - cost[node];

            for(auto &nbr : adj[node])
            {
                auto[nbrnode , nbrtime] = nbr;
                if(time + nbrtime < dist[nbrnode][newpower])
                {
                    dist[nbrnode][newpower] = nbrtime + time;
                    pq.push({dist[nbrnode][newpower] , nbrnode , newpower});
                }
            }
        }
    }

    vector<long long> minTimeMaxPower(int n, vector<vector<int>>& edges, int power, vector<int>& cost, int source, int target) {
        for(auto it : edges) adj[it[0]].push_back({it[1] , it[2]});

        dist.resize(n , vector<ll>(power+1 , LLONG_MAX));

        Dijkstra(n , power , cost , source , target);

        ll optimalpower = -1;   
        ll optimaltime = LLONG_MAX;

        for(int i = power ; i>=0 ; i--)
        {
            if(dist[target][i] < optimaltime) 
            {
                optimaltime = dist[target][i];
                optimalpower = i;
            }
        }

        if(optimaltime == LLONG_MAX) return {-1,-1};
        else return {optimaltime , optimalpower};
    }
};