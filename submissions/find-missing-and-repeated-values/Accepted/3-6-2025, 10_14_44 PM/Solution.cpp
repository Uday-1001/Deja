// https://leetcode.com/problems/find-missing-and-repeated-values

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int>ans(2);
        unordered_map<int,int>mapping;
        int n = grid.size();
        int m = grid[0].size();

        for(int i =1; i<=n*m ;i++)
        {
            mapping[i] = 1;
        }

        for(int i= 0; i<n ; i++)
        {
            for(int j = 0 ; j<m ;j++)
            {
                mapping[grid[i][j]]--;
            }
        }
        for(auto it : mapping)
        {
            if(it.second == -1)
            ans[0] = it.first;

            else if(it.second == 1)
            ans[1] = it.first;
        }
        return ans;
        
    }
};