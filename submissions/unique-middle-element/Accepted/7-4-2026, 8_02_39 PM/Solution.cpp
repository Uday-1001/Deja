// https://leetcode.com/problems/unique-middle-element

class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;

        for(auto it : nums) mp[it]++;
        return mp[nums[n/2]] == 1;
    }
};