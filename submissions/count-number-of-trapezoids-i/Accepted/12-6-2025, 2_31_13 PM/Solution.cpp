// https://leetcode.com/problems/count-number-of-trapezoids-i

class Solution {
public:
    const int mod = 1e9+7;
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<long long , long long>mp;

        for(int i=0 ; i<points.size() ; i++)
        {
            mp[points[i][1]]++;
        }

        long long possible_combo = 0;
        long long prev_lines = 0;
        for(auto it : mp)
        {
            long long variations = (((it.second * (it.second - 1)) % mod) / 2) % mod;
            possible_combo += (prev_lines * variations) % mod;
            prev_lines += variations;
        }
        
    return possible_combo % mod;
    }
};