// https://leetcode.com/problems/power-grid-maintenance

class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        vector<int>ans;
        unordered_map<int,int>grid;
        unordered_map<int,bool>station;

        for(int i =1 ; i<=c ; i++) station[i] = true;

        for(auto pairs : connections)
        {
            grid[pairs[0]] = pairs[1];
        }

        for(auto query : queries)
        {
            if(query[0] == 1 and station[query[1]] == true)
            {
                ans.push_back(query[1]);
            }
            else if(query[0] == 2 and station[query[1]] == true)
            {
                station[query[1]] = false;
            }
            else if(query[0] == 1 and station[query[1]] == false)
            {
                if(grid.size() > 0)
                ans.push_back(grid[query[1]]);
                else
                ans.push_back(-1);
            }
        } 
        return ans;

    }
};