// https://leetcode.com/problems/jump-game-ii

class Solution {
public:
    void solve(vector<int>&nums ,int i, int &ans , int step_count)
    {
        if(i == nums.size()-1)
        {
            ans = min(ans, step_count);
            return ;
        }
        if(i >= nums.size()) return ;
        
        for(int jumping =1 ; jumping <= nums[i] ; jumping++)  
        
            solve(nums, i + jumping ,ans, step_count + 1);

    }
    int jump(vector<int>& nums) {
        int ans= INT_MAX;
        solve(nums,0,ans,0);
        return ans ;
    }
};