// https://leetcode.com/problems/split-array-with-minimum-difference

class Solution {
public:
    using ll = long long;

    long long splitArray(vector<int>& nums) {
        int n = nums.size();
        vector<bool>incseq(n , false);
        vector<bool>decseq(n , false);

        incseq[0] = true;
        decseq[n-1] = true;

        for(int i = 1 ; i<n ; i++) incseq[i] = incseq[i-1] and (nums[i] > nums[i-1]);
        for(int i = n-2 ; i>=0 ; i--) decseq[i] = decseq[i+1] and (nums[i] > nums[i+1]);

        ll sum = accumulate(begin(nums) , end(nums) , 0LL);

        ll leftsum = nums[0];
        ll rightsum = sum - nums[0];
        ll ans = LLONG_MAX;

        if(incseq[0] == true and decseq[1] == true) ans = min(ans , abs(leftsum - rightsum));

        for(int i = 1; i<n-1 ; i++)
        {
            leftsum += nums[i];
            rightsum -= nums[i];

            ll diff = abs(leftsum - rightsum);

            if(incseq[i] == true and decseq[i+1] == true) ans = min(ans , (diff));
        }
        return ans == LLONG_MAX ? -1 : ans;
    }
};