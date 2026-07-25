// https://leetcode.com/problems/first-missing-positive

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto it : nums) mp[it]++;

        for(int i=1 ; i<1e5 ; i++)
        {
            if(mp.count(i)) continue;
            else return i;
        }
        return 1;
    }
};