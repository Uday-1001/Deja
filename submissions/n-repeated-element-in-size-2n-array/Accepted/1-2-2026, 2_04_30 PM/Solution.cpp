// https://leetcode.com/problems/n-repeated-element-in-size-2n-array

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto num : nums) mp[num]++;
        
        for(auto it : mp)
        {
            if(it.second >= nums.size()/2) return it.first;
        }
    return 0;
    }
};