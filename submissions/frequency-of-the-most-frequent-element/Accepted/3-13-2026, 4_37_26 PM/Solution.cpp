// https://leetcode.com/problems/frequency-of-the-most-frequent-element

class Solution {
public:
    using ll = long long;
    int maxFrequency(vector<int>& nums, int k) {
       sort(nums.begin(), nums.end());
        int n = nums.size();

        int l = 0;
        ll sum = 0;
        int max_freq = 0;

        for(int r = 0 ; r<n ; r++)
        {
            sum += nums[r];

            while(((r - l + 1) * (long long)nums[r]) - sum > k) 
            {
                sum -= nums[l];
                l++;
            }

            max_freq = max(max_freq, r - l + 1);
        }
        return max_freq;
    }
};