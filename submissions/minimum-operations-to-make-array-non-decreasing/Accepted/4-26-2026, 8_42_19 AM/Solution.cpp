// https://leetcode.com/problems/minimum-operations-to-make-array-non-decreasing

class Solution {
public:
    using ll = long long;
    long long minOperations(vector<int>& nums) {
        int n = nums.size();

        ll ans = 0;
        ll prev_need = 0;

        for(int i = 0 ; i<n-1 ; i++){
            int curr_need = max(0LL , (nums[i] + prev_need) - nums[i+1]);

            if(curr_need > prev_need){
                ans += (curr_need - prev_need);
            }
            prev_need = curr_need;
        }
        return ans;
    }
};