// https://leetcode.com/problems/best-reachable-tower

class Solution {
public:
    static bool mycomp(const vector<int>&t1 , const vector<int>&t2)
    {
        if(t1[2] != t2[2]) return t1[2] > t2[2];

        if(t1[0] != t2[0]) return t1[0] < t2[0];
        return t1[1] < t2[1];
    }

    vector<int> bestTower(vector<vector<int>>& towers, vector<int>& centre, int radius) {
        sort(towers.begin() , towers.end() , mycomp);
        int x = centre[0] , y = centre[1];

        for(auto &t : towers)
        {
            int distance = abs(x - t[0]) + abs(y - t[1]);
            if(distance <= radius) return {t[0] , t[1]};
        }
    return {-1 , -1};
    }
};