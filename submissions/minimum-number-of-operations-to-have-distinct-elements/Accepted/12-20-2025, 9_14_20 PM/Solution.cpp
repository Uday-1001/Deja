// https://leetcode.com/problems/minimum-number-of-operations-to-have-distinct-elements

class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,bool>mp;
        mp[nums[nums.size()-1]] = true;
        
        int i = 0;
        for(i = nums.size()-1 ; i>0 ; i--){
            if(mp.find(nums[i-1]) == mp.end())
            {
                mp[nums[i-1]] = true;
            }
            else break;
        }
        int ans = i / 3;
        ans += i % 3 == 0 ? 0 : 1;
        return ans;
    }
};