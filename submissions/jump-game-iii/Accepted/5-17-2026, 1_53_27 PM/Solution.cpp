// https://leetcode.com/problems/jump-game-iii

class Solution {
public:
    set<int>st;
    vector<bool>vis;
    vector<bool>dp;

    bool byrec(vector<int>&arr , int i)
    {  
        if(i >= arr.size() or i < 0) return false;
        if(st.count(i)) return true;
        if(vis[i]) return false;
        if(dp[i] != false) return dp[i];

        vis[i] = true;

        bool go_left = byrec(arr , i - arr[i]);
        bool go_right = byrec(arr , i + arr[i]);

        return dp[i] = go_left or go_right;
    }

    bool canReach(vector<int>& arr, int start) {
        vis.assign(arr.size() , false);
        dp.assign(arr.size() , false);
        for(int i = 0 ; i<arr.size() ; i++) if(arr[i] == 0) st.insert(i);

        return byrec(arr , start);
    }
};