// https://leetcode.com/problems/minimum-bitwise-or-from-grid

class Solution {
public:
    bool ispossible(vector<vector<int>>& grid , int mid)
    {
        for(auto &it : grid){
            bool found = false;
            for(auto val : it){
                if((val | mid) == mid){
                    found = true;
                    break;
                }
            }
            if(!found) return false;
        }
    return true;
    }
    
    int minimumOR(vector<vector<int>>& grid) {
        int s = 0;
        int e = 0;
        for(auto &it : grid){
            for(auto val : it){
                e |= val;
            }
        }
        int ans = -1;

        while(s <= e){
            int mid = s + (e-s)/2;
            if(ispossible(grid , mid))
            {
                ans = mid;
                e = mid - 1;
            }
            else s = mid + 1;
        }
    return ans;
    }
};