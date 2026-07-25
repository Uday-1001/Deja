// https://leetcode.com/problems/minimum-subarray-length-with-distinct-sum-at-least-k

class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        int sum = 0;
        int l = 0;
        int ans = INT_MAX;
        unordered_map<int , int>mp;

        for(int r = 0 ; r < nums.size() ; r++){
            if(!mp.count(nums[r])) sum += nums[r];
            mp[nums[r]]++;
            
            //shrinking window
            while(sum >= k)
            {
                ans = min(ans , r - l + 1);
                mp[nums[l]]--;
                if(mp[nums[l]] == 0)
                {
                     sum -= nums[l];
                }
                l++;
            }
        }
    return ans == INT_MAX ? -1 : ans;
    }
};