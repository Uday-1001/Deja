// https://leetcode.com/problems/frequency-of-the-most-frequent-element

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin() , nums.end());
        int n =nums.size();

        int left = 0,right = 0,sum = 0;
        int max_freq =0;

        while(right < nums.size())
        {
            sum += nums[right];
            if(nums[n-1] == sum && n%2 == 0)
            {
                return n/2;
            }
            if(nums[n-1] == sum && n%2 != 0)
            {
                return n/2;
            }  

            int no_of_ops = (right-left+1)*n - sum ;

            while(no_of_ops > k)
            {
                sum -= nums[left];
                left++;
            }

            max_freq = max(max_freq , (right-left+1));
            right++;
        }
    return max_freq;
    }
};