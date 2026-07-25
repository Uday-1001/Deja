// https://leetcode.com/problems/3sum-closest

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int sum = 0;
        int min_diff = INT_MAX;
        int k = 3;
        int ans = 0;

        sum = accumulate(nums.begin() , nums.begin()+k , 0);

        if(target - sum < min_diff) 
        {
            ans = sum;
            min_diff = min(min_diff , sum - target);
        }

        for(int i=k ; i<nums.size() ; i++)
        {
            int to_be_removed = nums[i-k];
            int to_be_added = nums[i];

            sum -= to_be_removed;
            sum += to_be_added;

            if(target - sum < min_diff) 
            {
                ans = sum;
                min_diff = min(min_diff , sum - target);
            }
        }
    return ans;
    }
};