// https://leetcode.com/problems/network-recovery-pathways

class Solution {
public:
    int n;
    using ll = long long;
    using pi = pair<ll,int>;

    unordered_map<int , vector<pi>>adj;
    vector<ll>pathcosts;

    bool DijkstraAlgo(int dest , ll midvalue , ll k)
    {
        vector<ll>dist(n , LLONG_MAX);
        dist[0] = 0;
        priority_queue<pi , vector<pi> , greater<pi>>pq;

        pq.push({0 , 0});
        while(!pq.empty())
        {
            auto[cost , node] = pq.top();
            pq.pop();

            if(cost > k) return false;
            if(node == dest) return true;

            for(auto nbr : adj[node])
            {
                auto[nbrcost , nbrnode] = nbr;
                if(nbrcost < midvalue) continue;

                if(nbrcost + cost < dist[nbrnode])
                {
                    dist[nbrnode] = cost + nbrcost;
                    pq.push({dist[nbrnode] , nbrnode});
                }
            }
        }
        return false;
    }

    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        n = online.size();
        for(auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            ll cost = it[2];

            if(online[u] and online[v]) adj[u].push_back({cost , v});
            pathcosts.push_back(cost);
        }

        sort(begin(pathcosts) , end(pathcosts));
        pathcosts.erase(unique(begin(pathcosts) , end(pathcosts)) , end(pathcosts));

        int st = 0;
        int end = pathcosts.size()-1;

        ll ans = -1;

        while(st <= end)
        {
            int mid = st + (end - st)/2;
            if(DijkstraAlgo(n-1 , pathcosts[mid] , k))
            {
                ans = mid;
                st = mid + 1;
            }
            else end = mid - 1;
        }

        return ans == -1 ? -1 : (int)pathcosts[ans];
    }
};