// https://leetcode.com/problems/get-biggest-three-rhombus-sums-in-a-grid

class Solution {
public:

    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        vector<int>ans;
        priority_queue<int>pq;
        set<int>st;

        int n = grid.size();
        int m = grid[0].size();

        int sum = 0;
        for(int i=0 ; i<n ; i++)
        {
            for(int j=0 ; j<m ; j++)
            {
                pq.push(grid[i][j]);

                int sum = 0;
                for(int radius=1 ; i-radius >= 0 && i+radius < n && j-radius >= 0 && j+radius < m ; radius++)
                {
                    sum += grid[i+radius][j];
                    sum += grid[i-radius][j];
                    sum += grid[i][j+radius];
                    sum += grid[i][j-radius];
                }
                pq.push(sum);
            }
        }

        int req = 3;
        while(!pq.empty() && req--)
        {
            st.insert(pq.top());
            pq.pop();
        }

        for(auto it : st) ans.push_back(it);
        reverse(rbegin(ans) , rend(ans));
        return ans;
    }
};