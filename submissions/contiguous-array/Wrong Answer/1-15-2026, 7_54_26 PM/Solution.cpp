// https://leetcode.com/problems/contiguous-array

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        vector<int>modified(nums.size() , 1);
        for(int i = 0 ;i < nums.size() ; i++) if(nums[i] == 0) modified[i] = -1;

        vector<int>cumsum(nums.size() , 0);
        cumsum[0] = modified[0];
        for(int i = 1 ; i<modified.size() ; i++)
        {
            cumsum[i] = cumsum[i-1] + modified[i];
        }

        int maxlen = 0;
        unordered_map<int,int>mp;
        int sum = 0;

        if(cumsum.size() == 2 and cumsum[0] == -1 and cumsum[1] == 0) return 2;
        if(cumsum.size() == 2 and cumsum[0] == 0 and cumsum[1] == -1) return 2;

        for(int i = 0 ; i<nums.size() ; i++)
        {
            sum = cumsum[i];

            if(mp.count(sum)) maxlen = max(maxlen , i - mp[sum]);
            else mp[sum] = i;
        }
    return maxlen;
    }
};