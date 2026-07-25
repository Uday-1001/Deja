// https://leetcode.com/problems/majority-element

class Solution {
public:

    int ans = 0;
    
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>hash;
        int n = nums.size();

        for(int i=0 ; i<nums.size() ; i++)
        {
            hash[nums[i]]++;
        }

        for(auto it : hash)
        {
            int key = it.second;
            if(key > (n/2))
            ans = it.first;
        }
    return ans;
    }
};