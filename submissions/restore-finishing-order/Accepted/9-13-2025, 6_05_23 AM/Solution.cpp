// https://leetcode.com/problems/restore-finishing-order

class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        unordered_map<int,int>mp;
        vector<int>ans;
        
        for(auto f : friends)
        {
            mp[f]++;
        }

        for(auto elem : order)
        {
            if(mp[elem] == 1)
            {
                ans.push_back(elem);
            }
        }
    return ans;
    }
};