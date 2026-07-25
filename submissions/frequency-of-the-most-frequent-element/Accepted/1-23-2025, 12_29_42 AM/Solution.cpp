// https://leetcode.com/problems/frequency-of-the-most-frequent-element

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
       sort(nums.begin(), nums.end());
        int n = nums.size();

        int left = 0, right = 0;
        long long sum = 0;
        int max_freq = 0;

        while (right < n) {
            sum += nums[right];

            // Corrected calculation for the number of operations required
            while ((right - left + 1) * (long long)nums[right] - sum > k) {
                sum -= nums[left];
                left++;
            }

            max_freq = max(max_freq, right - left + 1);
            right++;
        }
        return max_freq;
    }
};