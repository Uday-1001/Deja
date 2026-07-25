// https://leetcode.com/problems/contains-duplicate-ii

class Solution {
public:
    bool checkpresent(vector<int>&pos , int k)
    {
        for(int i = 0 ; i<pos.size() ; i++)
        {
            for(int j = i+1 ; j<pos.size() ; j++)
            {
                if(abs(pos[i] - pos[j]) <= k) return true;
                else continue;
            }
        }
    return false;
    }

    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int , vector<int>>mp;

        for(int i = 0 ; i<nums.size() ; i++) mp[nums[i]].push_back(i);
        for(auto it : mp)
        {
            vector<int>pos = it.second;
            if(pos.size() == 1) continue;
            else 
            {
                if(checkpresent(pos , k)) return true;
            }
        }
    return false;  
    }
};