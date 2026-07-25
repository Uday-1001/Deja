// https://leetcode.com/problems/two-sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;

        for(int i = 0 ; i<nums.size() ; i++)
        {
            int num = nums[i];
            int tosearch = target - num;
            if(mp.find(tosearch) != mp.end())
            {
                return {mp[tosearch] , i};
            }
            mp[num] = i;
        }
    return {};
    }
};