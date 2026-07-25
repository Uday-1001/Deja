// https://leetcode.com/problems/the-two-sneaky-numbers-of-digitville

class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int,int>mp;
        vector<int>ans;

        for(auto num : nums) mp[num]++;

        for(auto elem : mp) if(elem.second >= 2) ans.push_back(elem.first);
        return ans;
    }
};