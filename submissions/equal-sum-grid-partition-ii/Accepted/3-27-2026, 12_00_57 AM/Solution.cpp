// https://leetcode.com/problems/equal-sum-grid-partition-ii

class Solution {
public:
    using ll = long long;

    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        ll total = 0;
        for(auto it : grid) for(auto x : it) total += x;

    {
        unordered_map<ll,ll>up , down;
        for(auto it : grid) for(auto x : it) down[x]++;

        ll upsum = 0;

        for(int i = 0 ; i<n-1 ; i++)
        {
            for(int j = 0 ; j<m ; j++)
            {
                down[grid[i][j]]--;
                up[grid[i][j]]++;

                if(down[grid[i][j]] == 0) down.erase(grid[i][j]);
                upsum += grid[i][j];
            }

            ll downsum = total - upsum;
            if(downsum == upsum) return true;

            ll diff = upsum - downsum;
            if(diff > 0)
            {
                if(up.count(diff))
                {
                    //means that the element to be removed is of the upper partition 
                    int rows = i+1;
                    int cols = m;
                    if(rows >= 2 and cols >= 2) return true;

                    if(rows == 1) if(grid[0][0] == diff or grid[0][m-1] == diff) return true;
                    if(cols == 1) 
                    {
                        if(grid[0][0] == diff or grid[i][0] == diff) return true;
                    }
                }
            }
            else
            {
                diff = abs(diff);
                if(down.count(diff))
                {
                    //means that the element to be removed is of the lower partition 
                    int rows = n-(i+1);
                    int cols = m;
                    if(rows >= 2 and cols >= 2) return true;

                    if(rows == 1) if(grid[i+1][0] == diff or grid[i+1][m-1] == diff) return true;
                    if(cols == 1) 
                    {
                        if(grid[i+1][0] == diff or grid[n-1][0] == diff) return true;
                    }
                }
            }
        }
    }
    //Now , we check for vertical cuts across Grid
    {
        unordered_map<ll,ll>left , right;
        for(auto it : grid) for(auto x : it) right[x]++;

        ll leftsum = 0;

        for(int j = 0 ; j<m-1 ; j++)
        {
            for(int i = 0 ; i<n ; i++)
            {
                right[grid[i][j]]--;
                left[grid[i][j]]++;

                if(right[grid[i][j]] == 0) right.erase(grid[i][j]);
                leftsum += grid[i][j];
            }

            ll rightsum = total - leftsum;
            if(rightsum == leftsum) return true;

            ll diff = leftsum - rightsum;
            if(diff > 0)
            {
                if(left.count(diff))
                {
                    //means that the element to be removed is of the upper partition 
                    int rows = n;
                    int cols = j+1;
                    if(rows >= 2 and cols >= 2) return true;

                    if(rows == 1) if(grid[0][0] == diff or grid[0][j] == diff) return true;
                    if(cols == 1) 
                    {
                        if(grid[0][0] == diff or grid[n-1][0] == diff) return true;
                    }
                }
            }
            else
            {
                diff = abs(diff);
                if(right.count(diff))
                {
                    //means that the element to be removed is of the lower partition 
                    int rows = n;
                    int cols = m-(j+1);
                    if(rows >= 2 and cols >= 2) return true;

                    if(rows == 1) if(grid[0][j+1] == diff or grid[0][m-1] == diff) return true;
                    if(cols == 1) 
                    {
                        if(grid[0][j+1] == diff or grid[n-1][j] == diff) return true;
                    }
                }
            }
        }
    }
        return false;
    }
};