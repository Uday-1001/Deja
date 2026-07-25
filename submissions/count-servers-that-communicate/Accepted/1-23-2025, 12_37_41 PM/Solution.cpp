// https://leetcode.com/problems/count-servers-that-communicate

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> row_counter(n,0);
        vector<int> col_counter(m,0);
        

        for(int i =0 ;i<n ;i++)
        {
            for(int j =0; j<m ; j++)
            {
                if(grid[i][j] == 1)
                {
                    row_counter[i] += 1;
                    col_counter[j] += 1;
                }
            }
        }
    int count = 0;
    for(int i =0 ;i<n ;i++)
        {
            for(int j =0; j<m ; j++)
            {
                if(grid[i][j] == 1)
                {
                    if(row_counter[i] >=2 && col_counter[j] >= 2)
                    {
                        count ++;
                    }
                    else if(row_counter[i] >=2)
                    {
                        count ++;
                    }
                    else if(col_counter[j] >=2)
                    {
                        count ++;
                    }
                }
            }
        }
    return count;
    }
};