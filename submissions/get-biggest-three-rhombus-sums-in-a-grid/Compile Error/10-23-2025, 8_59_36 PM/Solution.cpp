// https://leetcode.com/problems/get-biggest-three-rhombus-sums-in-a-grid

class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        priority_queue<int>pq;
        vector<int>ans;

        for(int i=0 ; i<n ; i++)
        {
            for(int j=0 ; j<m ; j++)
            {
                int cell = grid[i][j];
                pq.push(cell);

                for(int radius=1 ; ;radius++)
                {
                    int up = i-radius;
                    int down = i+radius;
                    int left = j-radius;
                    int right = j+radius;

                    if(up < 0 or down >= n or left < 0 or right >= m) break;

                    int sum = 0;

                    for(int i=0 ; i<radius ; i++)
                    {
                        sum += grid[up+i][j+i];
                    }
                    for(int i=0 ; i<radius ; i++)
                    {

                    }
                    for(int i=0 ; i<radius ; i++)
                    {
                        
                    }

                
                }
            }
        }
    }
};