// https://leetcode.com/problems/check-if-array-is-good

class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int , int>mp;

        for(auto it : nums) mp[it]++;
        for(auto it : mp)
        {
            if(it.first != n-1) 
            {
                if(it.second > 1) return false;
            }
            else 
            {
                if(it.second != 2) return false;
            }
        }
        return true;
    }
};