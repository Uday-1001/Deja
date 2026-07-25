// https://leetcode.com/problems/count-subarrays-with-cost-less-than-or-equal-to-k

class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        int l = 0;
        deque<int>maxi;
        deque<int>mini;

        int count = 0;
        for(int r = 0 ; r<n ; r++)
        {
            int curr = nums[r];
            while(!maxi.empty() and nums[maxi.back()] <= curr)
            {
                maxi.pop_back();
            }
            maxi.push_back(r);

            while(!mini.empty() and nums[mini.back()] >= curr)
            {
                mini.pop_back();
            }
            mini.push_back(r);

            while(((nums[maxi.front()] - nums[mini.front()]) * (r-l+1)) > k)
            {
                if(mini.front() == l) mini.pop_front();
                if(maxi.front() == l) maxi.pop_front();
                l++;
            }
            count += (r-l+1);
        }
        return count;
    }
};