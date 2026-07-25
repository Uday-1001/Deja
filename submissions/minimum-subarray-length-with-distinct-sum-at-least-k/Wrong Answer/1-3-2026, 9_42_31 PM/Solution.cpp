// https://leetcode.com/problems/minimum-subarray-length-with-distinct-sum-at-least-k

class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        int sum = 0;
        int l = 0;
        int ans = INT_MAX;;

        for(int r = 0 ; r<nums.size() ; r++){
            sum += nums[r];
            //shrinking condition
            if(sum >= k)
            {
                ans = min(ans , r - l + 1);
                sum -= nums[l++];
            }
            else continue;
        }
    return ans == INT_MAX ? -1 : ans;
    }
};