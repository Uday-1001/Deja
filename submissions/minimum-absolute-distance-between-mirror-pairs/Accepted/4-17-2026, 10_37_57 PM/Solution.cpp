// https://leetcode.com/problems/minimum-absolute-distance-between-mirror-pairs

class Solution {
public:
    int reversefxn(int x)
    {
        int rev = 0;
        while(x > 0)
        {
            rev = rev * 10 + x % 10;
            x /= 10;
        }
        return rev;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int,int>mp;
        int ans = INT_MAX;
        
        for(int i = 0 ; i<nums.size() ; i++)
        {
            if(mp.count(nums[i])) ans = min(ans , i - mp[nums[i]]);
            int reverse = reversefxn(nums[i]);
            mp[reverse] = i;
        }
        return ans == INT_MAX ? -1 : ans;
    }
};