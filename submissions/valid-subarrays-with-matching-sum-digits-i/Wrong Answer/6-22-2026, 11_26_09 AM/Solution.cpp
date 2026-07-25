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
                bool lastdigit = false;
                bool firstdigit = false;

                if(sum < 10 and sum == x) count++;

                while(sum >= 10)
                {
                    int digit = sum % 10;
                    if(!lastdigit and digit == x) lastdigit = true;
                    sum /= 10;
                }
                if(!firstdigit and sum == x) firstdigit = true;

                if(firstdigit and lastdigit) count++;
            }
        }
        return count;
    }
};