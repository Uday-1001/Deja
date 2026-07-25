// https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation

class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();

        unordered_map<string , int>mp;

        for(auto it : mat)
        {
            string s = "";
            for(auto x : it) s += (x + '0');
            mp[s]++;
        }

        for(auto it : target)
        {
            string t = "";
            for(auto x : it) t += (x + '0');
            if(!mp.count(t)) return false;
        }

        return true;

    }
};