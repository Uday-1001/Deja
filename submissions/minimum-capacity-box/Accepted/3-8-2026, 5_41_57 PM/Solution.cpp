// https://leetcode.com/problems/minimum-capacity-box

class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        vector<pair<int,int>>vp;
        for(int i = 0 ; i<capacity.size() ; i++)
        {
            vp.push_back({capacity[i] , i});
        }
        sort(begin(vp) , end(vp));

        for(auto it : vp)
        {
            if(it.first >= itemSize) return it.second;
        }
        return -1;
    }
};