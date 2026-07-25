// https://leetcode.com/problems/filter-occupied-intervals

class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
        sort(begin(occupiedIntervals) , end(occupiedIntervals));

        vector<vector<int>>ans;
        vector<vector<int>>merged;

        for(auto it : occupiedIntervals){
            if(merged.empty() or merged.back()[1]+1 < it[0]) merged.push_back(it);
            else merged.back()[1] = max(merged.back()[1] , it[1]);
        }

        for(auto it : merged){
            int st = it[0];
            int end = it[1];
            if(st > freeEnd or end < freeStart) ans.push_back({st , end});
            else 
            {
                if(st < freeStart) ans.push_back({st , freeStart - 1});
                if(end > freeEnd) ans.push_back({freeEnd + 1 , end});
            }
        }
        return ans;
    }
};