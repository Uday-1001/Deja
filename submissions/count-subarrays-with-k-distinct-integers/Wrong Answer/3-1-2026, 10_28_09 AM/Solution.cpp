// https://leetcode.com/problems/count-subarrays-with-k-distinct-integers

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k, int m) {
        int n = nums.size();

        unordered_map<int, int> mp;
        long long cnt = 0;

        int i = 0;
        int j = 0;
        int goodcnt = 0;
        // long long prefix = 0;

        while (j < n) {
            mp[nums[j]]++;

            if (mp[nums[j]] == m)
                goodcnt++;

            while (mp.size() > k) {

                if (mp[nums[i]] == m)
                    goodcnt--;
                mp[nums[i]]--;
                if (mp[nums[i]] == 0)
                    mp.erase(nums[i]);
                i++;
                // prefix=0;
            }

            while (mp[nums[i]] > m) {
                mp[nums[i]]--;
                i++;
                // prefix++;
            }

            if (mp.size() == k && goodcnt == k) {
                cnt += 1;
            }
            j++;
        }

        return cnt;
    }
};