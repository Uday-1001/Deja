// https://leetcode.com/problems/valid-subarrays-with-matching-sum-digits-i

class Solution {
public:
    int countValidSubarrays(vector<int>& nums, int x) {
        vector<int>pref(nums.size() , 0);
        pref[0] = nums[0];
        for(int i = 1 ; i<nums.size() ; i++) pref[i] = pref[i-1] + nums[i];

        int count = 0;
        for(int i = 0 ; i<nums.size() ; i++)
        {
            for(int j = i ; j<nums.size() ; j++)
            {
                int sum = pref[j] - ((i-1) >= 0 ? pref[i-1] : 0);

                int val = sum;

                int lastDigit = val % 10;

                while(val >= 10) val /= 10;

                int firstDigit = val;

                if(firstDigit == x and lastDigit == x) count++;
            }
        }
        return count;
    }
};