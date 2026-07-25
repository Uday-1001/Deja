// https://leetcode.com/problems/get-biggest-three-rhombus-sums-in-a-grid

class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        priority_queue<long long, vector<long long>, greater<long long>> pq;
        set<long long> seen;
        vector<int> ans;

        for(int i = 0; i < n; i++) 
        {
            for(int j = 0; j < m; j++) 
            {
                long long val = grid[i][j];
                
                if(seen.insert(val).second) 
                {
                    pq.push(val);
                    if (pq.size() > 3) 
                    {
                        pq.pop();
                    }
                }

                // Expand the rhombus for different radii 
                for(int radius = 1; ; radius++) 
                {
                    int up = i - radius;
                    int down = i + radius;
                    int left = j - radius;
                    int right = j + radius;

                    // Out of bound condition
                    if (up < 0 || down >= n || left < 0 || right >= m) break;

                    long long sum = 0;
                    
                    for (int k = 0; k < radius; k++) 
                    {
                        sum += grid[up + k][j + k];
                    }
                    for (int k = 0; k < radius; k++) 
                    {
                        sum += grid[i + k][right - k];
                    }
                    for (int k = 0; k < radius; k++) 
                    {
                        sum += grid[down - k][j - k];
                    }
                    for (int k = 0; k < radius; k++) 
                    {
                        sum += grid[i - k][left + k];
                    }

                    if (seen.insert(sum).second) 
                    {
                        pq.push(sum);
                        if (pq.size() > 3) 
                        {
                            pq.pop(); 
                        }
                    }
                }
            }
        }

        // Extract the elements from the min-heap
        while(!pq.empty()) 
        {
            ans.push_back(pq.top());
            pq.pop();
        }

        // Reversing the vector to get the sums in descending order
        reverse(ans.begin(), ans.end());

        return ans;
    }
};