// https://leetcode.com/problems/maximum-alternating-subsequence-sum

class Solution {
public:
    typedef long long ll;

    ll ans = 0;

    void solve(vector<int>& nums, ll val, bool flag, int i){
        // base case
        if(i >= nums.size()){
            ans = max(ans, val);
            return;
        }

        // include
        if(flag == true){
            solve(nums, val+nums[i], !flag, i+1);
        } 
        else{
            solve(nums, val-nums[i], !flag, i+1);
        }
        // exclude
        solve(nums, val, flag, i+1);
    }


    long long maxAlternatingSum(vector<int>& nums) {
        ll val = 0;
        bool flag = true;
        // true -> even index aaya hai
        // false means odd index aaya hai
        solve(nums, val, flag, 0);
        return ans;
    }
};