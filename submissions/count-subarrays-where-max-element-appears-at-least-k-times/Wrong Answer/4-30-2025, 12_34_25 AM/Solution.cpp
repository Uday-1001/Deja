// https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maximum = *max_element(begin(nums) , end(nums));
        int max_count = 0;
        int ans = 0;

        int left = 0;
        int right = 0;
        while(right < nums.size())
        {
            if(nums[right] == maximum)
            {
                max_count++;
            }
            while(max_count >= k)
            {
                ans += (nums.size() - right);
                if(nums[left] == maximum)
                {
                    max_count--;
                }
                left++;
            }
            right++;
        }
    return ans;
    }
};