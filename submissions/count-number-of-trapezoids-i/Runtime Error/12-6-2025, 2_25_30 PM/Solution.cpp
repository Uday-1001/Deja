// https://leetcode.com/problems/count-number-of-trapezoids-i

class Solution {
public:
    const int mod = 1e9+7;
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int , int>mp;
        int trapezoids = 0;
        int same_y_coord = 0;

        for(int i=0 ; i<points.size() ; i++)
        {
            mp[points[i][1]]++;
        }

        int possible_combo = 0;
        int prev_lines = 0;
        for(auto it : mp)
        {
            int variations = (it.second * (it.second - 1)) / 2;
            possible_combo += (prev_lines * variations) % mod;
            prev_lines += variations;
        }
        
    return possible_combo;
    }
};