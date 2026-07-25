// https://leetcode.com/problems/toggle-light-bulbs

class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        vector<int>ans;
        set<int>st;
        for(auto it : bulbs){
            if(!st.count(it)) st.insert(it);
            else st.erase(it);
        }
        for(auto it : st) ans.push_back(it);
        return ans;
        
    }
};