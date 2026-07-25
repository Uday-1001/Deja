// https://leetcode.com/problems/path-with-maximum-probability

class Solution {
public: 
    using pi = pair<double,int>;
    unordered_map<int , vector<pi>>adjlist;

    int dijkstra(int n , int src , int dest , vector<double>&probab)
    {
        probab[src] = 1.0;

        priority_queue<pi>pq;
        pq.push({1.0 , src});

        while(!pq.empty())
        {
            auto[p , node] = pq.top();
            pq.pop();

            if(node == dest) return probab[dest];

            for(auto &it : adjlist[node])
            {
                auto[pr , nbr] = it;
                if(p * pr > probab[nbr])
                {
                    probab[nbr] = p * pr;
                    pq.push({probab[nbr] , nbr});
                }
            }
        }
    return 0.0;
    }

    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        for(int i = 0 ; i<edges.size() ; i++)
        {
            int src = edges[i][0];
            int dest = edges[i][1];
            double prob = succProb[i];
            
            adjlist[src].push_back({prob , dest});
            adjlist[dest].push_back({prob , src});
        }

        vector<double>probab(n , 0.0);

        return dijkstra(n , start_node , end_node , probab);
    
    }
};