// https://leetcode.com/problems/count-covered-buildings

class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int , int>maxi_x;
        unordered_map<int , int>mini_x;
        unordered_map<int , int>maxi_y;
        unordered_map<int , int>mini_y;

        for(auto &pt : buildings)
        {
            int x = pt[0];
            int y = pt[1];

            if(!mini_x.count(y)) mini_x[y] = x;
            else 
                mini_x[y] = min(mini_x[y], x);

            if(!maxi_x.count(y)) maxi_x[y] = x;
            else 
                maxi_x[y] = max(maxi_x[y], x);

            if(!mini_y.count(x)) mini_y[x] = y;
            else 
                mini_y[x] = min(mini_y[x], y);

            if(!maxi_y.count(x)) maxi_y[x] = y;
            else 
                maxi_y[x] = max(maxi_y[x], y);
        }

        int covered_buildings = 0;
        for(auto &it : buildings)
        {
            int x = it[0];
            int y = it[1];

            if(x > mini_x[y] && x < maxi_x[y] && y > mini_y[x] && y < maxi_y[x])
                covered_buildings++;
        }

    return covered_buildings;
    }
};